slice([H|_], 1,1,[H]).

slice([H|T],1, End, [H|L]):-
  End > 1,
  NewE is End - 1,
  slice(T, 1, NewE, L).

slice([H|T],Begin, End, L):-
  Begin > 1,
  NewB is Begin -1,
  NewE is End - 1,
  slice(T, NewB, NewE, L).
