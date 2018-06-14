# last(List, X):- reverse(List, [X|_]).

# last([a,b,c], c).

last([X], X).
last([_|L], X):- last(L, X).