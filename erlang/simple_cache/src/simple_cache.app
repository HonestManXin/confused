{
	application,simple_cache,
	[{description,"A Simple Cacheing system"},
	{vsn,"0.0.1"},
	{modules,[sc_app,sc_sup,simple_cache,sc_element,sc_store]},
	{registered,[sc_sup]},
	{applications,[kernel,stdlib]},
	{mod,{sc_app,[]}}
	]
}.