-module(sc_store).
-compile(export_all).
-define(TABLE_ID, ?MODULE).
-export([init/0,insert/2,lookup/1,delete/1]).

init() ->
	ets:new(?TABLE_ID,[public,named_table]),
	ok.

insert(Key,Value) ->
	ets:insert(?TABLE_ID,{Key,Value}).

lookup(Key) ->
	case ets:lookup(?TABLE_ID,Key) of 
		[{Key,Pid}] ->
			{ok,Pid};
		[] ->
			{error,not_found}
	end.

delete(Pid) ->
	ets:match_delete(?TABLE_ID,{'_',Pid}).




