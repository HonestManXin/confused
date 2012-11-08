-module(sc_element).
-behaviour(gen_server).
-define(SERVER,?MODULE).
-define(DEFAULT_LEASE_TIME,(60 * 60 * 24)).
-record(state, {value,lease_time,start_time}).

create(Value,LeaseTime) ->
	sc_sup:start_child(Value,LeaseTime).
create(Value) ->
	sc_sup:start_child(Value,?DEFAULT_LEASE_TIME).

fetch(Pid) ->
	gen_server:call(Pid,fetch).
replace(Pid,Value) ->
	gen_server:cast(Pid,{replace,Value}).
delete(Pid) ->
	gen_server:cast(Pid,delete).

start_link(Value,LeaseTime) ->
	gen_server:start_link(?MODULE,{Value,LeaseTime},[]).

init([Value,LeaseTime]) ->
	Now = calendar:local_time(),
	Start_Time = calendar:datetime_to_gregorian_seconds(Now),
	{ok,#state{value = Value,lease_time = LeaseTime,start_time=Start_Time},
	time_left(Start_Time,LeaseTime)}.

time_left(_Start_Time,infinity) ->
	infinity;
time_left(Start_Time,LeaseTime) ->
	Now = calendar:local_time(),
	Current_Time = calendar:datetime_to_gregorian_seconds(Now),
	TimeElapse = Current_Time - Start_Time,
	case LeaseTime - TimeElapse of 
		Time when Time < 0 ->
			0;
		Time ->
			Time * 1000
	end.

handle_call(fetch,_From,State) ->
	#state{value = Value,lease_time = LeaseTime,start_time = Start_Time} = State,
	TimeLeft = time_left(Start_Time,LeaseTime),
	{reply,{ok,Value},State,TimeLeft}.

handle_cast({replace,Value},State) ->
	#state{value = Value,lease_time = LeaseTime,start_time = Start_Time} = State,
	TimeLeft = time_left(Start_Time,LeaseTime),
	{noreply,State#state{value = Value},TimeLeft};
handle_cast(delete,State) ->
	{stop,normal,State}.

handle_info(timeout,State) ->
	{stop,normal,State}.

terminate() ->
	sc_store:delete(self()),
	ok.

code_change(_OldVsn,State,_Extra) ->
	{ok,State}.






