-module(sc_sup).
-behaviour(supervisor).
-compile(export_all).

-define(SERVER,?MODULE).

start_link() ->
	supervisor:start_link({local,?SERVER},?MODULE,[]).

init([]) ->
	Element = {sc_element,{sc_element,start_link,[]},
	temporary,brutal_kill,worker,[sc_element]},
	Children = [Element],
	RestartStratergy = {simple_one_for_one,0,1},
	{ok,{RestartStratergy,Children}}.








