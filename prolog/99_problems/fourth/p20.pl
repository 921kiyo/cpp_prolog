remove_at(H,[H|T], 1, T).
remove_at(X,[H|T1], C, [H|T2]):-
  C > 1,
  NewC is C - 1,
  remove_at(X, T1, NewC, T2).
