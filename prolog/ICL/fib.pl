f(1,1).
f(2,1).

f(N,R):-
  N > 2,
  N1 is N - 1,
  f(N1, R1),
  N2 is N - 2,
  f(N2, R2),
  R is R1 + R2.
