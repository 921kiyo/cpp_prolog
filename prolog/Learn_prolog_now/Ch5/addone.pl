addone([], []).
addone([H|T], [H1|T1]):- H1 is H+1, addone(T, T1).