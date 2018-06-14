pack([], []).
pack([X|Xs], [Z|Zs]):- transfer(X,Xs,Ys, Z), pack(Ys, Zs).

transfer(X,[], [], [X]).
transfer(X, [Y|Ys], [Y|Ys], [X]):- X \= Y.
transfer(X, [X|Xs], Ys, [X|Zs]):- transfer(X,Xs,Ys,Zs).

encode(L1, L2):- pack(L1, L), transform(L, L2).

transform([], []).
transform([[X|Xs]|Ys], [[N,X]|Zs]):- length([X|Xs], N), transform(Ys, Zs).