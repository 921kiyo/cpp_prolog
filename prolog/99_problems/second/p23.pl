:-use_module(library(random)).

remove_at(H, [H|T], 1, T).
remove_at(X, [H|T1], N, [H|T2]):-
  N > 1,
  New is N - 1,
  remove_at(X,T1,New, T2).

rnd_select(List, 0, []).
rnd_select(List, N, [R|T]):-
  N > 0,
  length(List, L),
  random(0, L, Index),
  remove_at(R, List, Index, NewList),
  NewN is N - 1,
  rnd_select(NewList,NewN, T).
