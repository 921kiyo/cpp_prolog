pairs([], []).
pairs([H|T1], [(A,B)|T2]):-
  A is H - 1,
  B is H + 1,
  pairs(T1, T2).
