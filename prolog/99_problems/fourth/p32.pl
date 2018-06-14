gcd(N1, N2, Res):- gcd(N1, N2, Res, N1).
gcd(N1, N2, Res, Res):-
  0 is N1 mod Res,
  0 is N2 mod Res.

gcd(N1, N2, Res, G):-
  A1 is N1 mod G,
  A2 is N2 mod G,
  \+((0 == A1, 0 == A2)),
  NewG is G - 1,
  gcd(N1, N2, Res, NewG).
