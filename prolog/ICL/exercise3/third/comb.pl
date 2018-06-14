comb(_, []).
comb([X|T], [X|Comb]):-
  comb(T, Comb).
comb([_|T], [X|Comb]):-
  comb(T, [X|Comb]).
