combination(N, List, Res):- combi(N, List, [], Res).

combi(N, List, Out, Out):-
  length(Out, N).

combi(N, List, In, Out):-
  length(In, Len),
  Len < N,
  member(A, List),
  \+(member(A, In)),
  append(In, [A], Mid),
  combi(N,List, Mid, Out).
