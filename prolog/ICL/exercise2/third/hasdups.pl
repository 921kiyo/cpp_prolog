hasdups([H|T]):-
  member(H, T).
hasdups([H|T]):-
  \+(member(H, T)),
  hasdups(T).
