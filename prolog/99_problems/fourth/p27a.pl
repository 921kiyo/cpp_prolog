group3(List1, G1, G2, G3):-
  transfer(List1, 2, G1, List2),
  transfer(List2, 3, G2, List3),
  transfer(List3, 4, G3, []).

transfer(L, 0, [], L).
transfer(List, N, [H|T], L):-
  N > 0,
  member(H, List),
  subtract(H, List, NewList),
  NewN is N - 1,
  transfer(NewList, NewN, T, L).


subtract(W, [W|T], T).
subtract(W, [H|T1], [H|T2]):-
  W \= H,
  subtract(W, T1, T2).
