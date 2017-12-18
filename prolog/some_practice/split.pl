
split(T,0, [], T).

split([H|T],N, [H|T1], L2):- 
    NewN is N-1, 
    split(T,NewN, T1, L2).