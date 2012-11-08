-module(sc_app).
-behaviour(application).
-compile(export_all).

start(_Start_Type,_Start_Args) ->
	case sc_sup:start_link() of 
		{ok,Pid} ->
			{ok,Pid};
		Other ->
			{error,Other}
	end.

stop(_State) ->
	ok.



