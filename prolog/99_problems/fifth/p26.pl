combination(N, List, Res):- combination(N,List, Res, []).
combination(N, List, Res, Res):- length(Res, N).

combination(N, List, Res, L):-
  member(H, List),
  \+(member(H,L)),
  combination(N, List, Res, [H|L]).
