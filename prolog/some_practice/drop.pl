getIndex(E, [E|_], 1).
getIndex(E, [_|T], N):-
    getIndex(E, T, N1),
    N is N1 + 1.

drop(L, N, Res):-
    findall(E, (member(E,L), getIndex(E,L,NE), mod(NE, N) =\= 0), Res).