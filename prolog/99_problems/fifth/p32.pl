gcd(N1, N2, G):- gcd(N1,N2,G,N1).

gcd(N1,N2,G,G):-
  N1 mod G =:= 0,
  N2 mod G =:= 0.

gcd(N1,N2,G,N):-
  N > 1,
  \+((N1 mod N =:= 0,N2 mod N =:= 0)),
  NewN is N - 1,
  gcd(N1,N2,G, NewN).
