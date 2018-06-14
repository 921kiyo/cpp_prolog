:- ensure_loaded(p10).

encode_modified(L1, L2):- encode(L1, L), strip(L, L2).

strip([], []).
strip([[1, X]|Ys], [X|Zs]):- strip(Ys, Zs).
strip([[N,X]| Ys], [[N,X]|Zs]):- N > 1, strip(Ys, Zs).