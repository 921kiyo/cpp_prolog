
split(T, 0, [], T).
split([H|T1], C, [H|T2], L2):-
  C > 0,
  NewC is C - 1,
  split(T1,NewC, T2, L2).

rotate(L1, N, L2):-
  N >= 0,
  length(L1, NL1),
  N1 is N mod NL1,
  rotate_left(L1,N1,L2).

rotate(L1, N, L2):-
  N < 0,
  length(L1, NL1),
  N1 is N mod NL1,
  rotate_left(L1,N1,L2).

rotate_left(L,0,L).
rotate_left(L1,N,L2):-
  N > 0,
  split(L1, N, S1, S2),
  append(S2,S1, L2).
