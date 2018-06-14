dot([], [], 0).
dot([H1|T1], [H2|T2], Result):-
  dot(T1, T2, NewResult),
  Result is NewResult + H1*H2.


rev(L, R):- accRev(L, [], R).

accRev([], A, A).
accRev([H|T], A, R):-
  accRev(T, [H|A], R).
