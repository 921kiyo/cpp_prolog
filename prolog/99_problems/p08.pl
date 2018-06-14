compress([], []).
compress([X], [X]).
compress([H,H|X], L):- compress([H|X], L).
compress([X,Y|Ys], [X|Zs]):- X \= Y, compress([Y|Ys], Zs).