element_at(X, [X|_], 1).
element_at(X, [_|T], E):- E>1, E1 is E-1, element_at(X, T, E1).