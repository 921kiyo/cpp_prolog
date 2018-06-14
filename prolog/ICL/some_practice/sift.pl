sift([], N, []).
sift([H|T], N, L):-
    H > N,
    sift(T, N, L).

sift([H|T], N, [H|L]):-
    H =< N,
    sift(T, N, L).