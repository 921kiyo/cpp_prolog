remove_at(X, [], 0, []).

remove_at(X, [H|T1], 0, [H|T2]):-
  remove_at(X, T1, 0, T2).

remove_at(H, [H|T1], 1, T2):-
  remove_at(H, T1, 0, T2).

remove_at(X, [H|T1], C, [H|T2]):-
  C > 1,
  NewC is C - 1,
  remove_at(X, T1, NewC, T2).
