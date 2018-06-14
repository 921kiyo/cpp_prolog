:- ensure_loaded(p23).

rnd_permu(List, Result):- length(List, X), rnd_select(List, X, Result).