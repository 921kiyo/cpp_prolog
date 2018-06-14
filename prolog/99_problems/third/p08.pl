compress([], []).
compress([H], [H]).

compress([H,H|T1], T2):-
  compress([H|T1],T2).

compress([H1,H2|T1], [H1|T2]):-
  H1 \= H2,
  compress([H2|T1],T2).
