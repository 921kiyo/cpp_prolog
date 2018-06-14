arc(a,b).
arc(c,f).
arc(f,e).
arc(b,c).
arc(d,f).
arc(b,d).
arc(c,e).

path(X,Z):- arc(X,Z).
path(X,Z):- arc(X,Y), path(Y,Z).


path2(X,Y, Path):- arc(X, Path), arc(Path, Y).

path2(X,Y,Path):- arc(X, Z), path2(Z, X, Path).
path2(X,Y,Path):- arc(X, Path), path2(Z, X, Path).


% even_odd([], [], []).
% even_odd([H|T], [H|T2], T3):- H mod 2 =:= 0, even_odd(T, T2,T3 ).
% even_odd([H|T], T2, [H|T3]):- H mod 2 =:= 1, even_odd(T, T2,T3 ).
last(E,L):- append(X, [E], L).

% last2(E,[]).
last2(E,[E]).
% last2(E, [H|T]):- last2(E, T).
last2(E, [H,Y|T]):- last2(E, [Y|T]).
