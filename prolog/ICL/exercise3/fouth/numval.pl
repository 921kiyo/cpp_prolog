numval(A,V):- number(A), V is A.
numval(A,V):- a(X,Y) = A, number(X), number(Y), V is X+Y.
numval(A,V):- m(X,Y) = A, number(X), number(Y), V is X*Y.

numval(A,V):-
  a(X,Y) = A,
  (\+(number(X));
  \+(number(Y))),
  numval(X, X1),
  numval(Y, Y1),
  V is X1+Y1.

numval(A,V):-
  m(X,Y) = A,
  (\+(number(X));
  \+(number(Y))),
  numval(X, X1),
  numval(Y, Y1),
  V is X1*Y1.
