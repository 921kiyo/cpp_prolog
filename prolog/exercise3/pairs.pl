pairs([],[]).
pairs([H|T], [(N,L)|T1]):- 
    N is H-1, L is H+1, 
    pairs(T, T1).