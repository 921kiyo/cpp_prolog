scalarMult(X, [], []).
scalarMult(X, [H|T], [H1|T1]):- H1 is H*X, scalarMult(X, T, T1).