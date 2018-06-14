split([],N, [], []).
split([H|T], N, [H|T1], T2):-  New is N -1, New > 0,split(T, New, T1, T2).
split([H|T], N, T1, [H|T2]):- split(T, N, T1, T2).
