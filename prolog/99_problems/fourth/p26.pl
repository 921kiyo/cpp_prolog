combination(0, _, [])  .
combination(N, List, [H|T]):-
  N > 0,
  member(H, List),
  subtract(H, List, NewList),
  NewN is N - 1,
  combination(NewN, NewList, T).

subtract(W, [W|T], T).
subtract(W, [H|T1], [H|T2]):-
  W \= H,
  subtract(W, T1, T2).
