plus(X, 0,X).
plus(X, s(Y), s(Z)):- plus(X,Y,Z).

odd(X):- plus(Z, Z, X).
