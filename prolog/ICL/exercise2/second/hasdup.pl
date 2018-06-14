hasdups(X):- hasdups(X, L), L \= [].

hasdups([], []).

hasdups([H|T], [H|T2]):-
  member(H, T),
  hasdups(T, T2).

hasdups([H|T], T2):-
  \+member(H, T),
  hasdups(T, T2).
