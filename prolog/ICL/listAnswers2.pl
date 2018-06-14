drop_more_item(L, N, NewL):- drop_more_item(L,N,NewL,[]).
drop_more_item([], _, [], _).
drop_more_item(L, 0, NewL, Removed):- check_dup(L, Removed, NewL).

drop_more_item([H|T1], N, NewL, T2):-
  N > 0,
  NewN is N -1,
  drop_more_item(T1, NewN, NewL, [H|T2]).

check_dup([], _, []).
check_dup([H|T1], Removed, [H|T2]):-
  \+(member(H, Removed)),
  check_dup(T1, Removed, T2).

check_dup([H|T1], Removed, T2):-
  member(H, Removed),
  check_dup(T1, Removed, T2).

count([], []).
count([H|T1], [(H,C)|T2]):-
  appear(H, [H|T1], C),
  remove_items(H, [H|T1], L),
  count(L, T2).

appear(_, [], 0).
appear(H, [H|T], C):-
  appear(H, T, NewC),
  C is NewC + 1.

appear(H1, [H2|T], C):-
  H1 \= H2,
  appear(H1, T, C).

remove_items(_, [], []).

remove_items(H1, [H2|T], [H2|L]):-
  H1 \= H2,
  remove_items(H1, T, L).
remove_items(H, [H|T], L):-
  remove_items(H, T, L).
