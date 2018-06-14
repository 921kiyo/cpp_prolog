gcd(X,0,X):- X > 0.
gcd(X,Y,G):-
  Y > 0,
  Z is X mod Y,
  gcd(Y,Z,G).


coprime(N1, N2):-
  gcd(N1,N2, 1).
