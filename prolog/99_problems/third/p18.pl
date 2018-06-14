slice([], 1, 0, []).

slice(_, 1, 0, []).

slice([H|T1], 1, X, [H|T2]):-
  X > 0,
  NewX is X - 1,
  slice(T1,1, NewX, T2).

slice([H|T1], X1,X2, T2):-
  X1 > 1,
  X2 > 0,
  NewX1 is X1 - 1,
  NewX2 is X2 - 1,
  slice(T1, NewX1, NewX2, T2).
