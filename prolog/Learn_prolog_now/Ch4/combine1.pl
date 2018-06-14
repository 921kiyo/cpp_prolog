combine1([], [], []).
combine1([X|TL1], [Y|TL2], [X,Y|TL3]):- combine1(TL1, TL2, TL3).