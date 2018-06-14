node(leaf(4), node(leaf(6), leaf(8))).


mirror(leaf(L),leaf(L)).
mirror(node(TL,TR),node(TL1,TR1)) :- mirror(TL,TR1), mirror(TR,TL1).

append1([], L, L).
append1([H|T], L2, [H|L3]):- append(T, L2, L3).

fringe(leaf(L), [L]).
fringe(node(L, R), Fringe):- 
    fringe(L, F1), 
    fringe(R, F2), 
    append1(F1, F2, Fringe).

