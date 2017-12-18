aibpairs([], []).
aibpairs([H|T1], [(H,L)|T2]):-
    L is 2 * H,
    aibpairs(T1, T2).
aibpairs([H|T1], [(H,L)|T2]):-
    L is H,
    aibpairs(T1, T2).
