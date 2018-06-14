contains(L1, L2, N):-
  append(A,List, L1),
  append(L2, _,List),
  length(A, NN),
  N is NN + 1.
