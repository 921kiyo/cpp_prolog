split(T, 0, [], T).
split([H|T1], C, [H|T2], L2):-
  C > 0,
  NewC is C - 1,
  split(T1,NewC, T2, L2).
