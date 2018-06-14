swap(leaf(A), leaf(A)).
swap(tree(A,B), tree(NewA,NewB)):-
  swap(A, NewA),
  swap(B, NewB).
