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

group3(List1, G1,G2,G3):-
  combination(2,List1, G1),
  subtract(G1, List1, List2),
  combination(3,List2, G2),
  subtract(G2, List2, List3),
  combination(4,List3, G3).

subtract(G, List, Res):-
  findall(X, (member(X, List), \+(member(X, G))), Res).
