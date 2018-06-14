split(T, 0, [], T).
split([H|T1], C, [H|T2], L2):-
  C > 0,
  NewC is C - 1,
  split(T1,NewC, T2, L2).

rotate(List, N, Res):-
  N > 0,
  length(List, Len),
  NewN is N mod Len,
  split(List, NewN, L1, L2),
  append(L2, L1, Res).

rotate(List, N, Res):-
  N < 0,
  length(List, Len),
  NewN is Len + N,
  NewN2 is NewN mod Len,
  split(List, NewN2, L1, L2),
  append(L2, L1, Res).
