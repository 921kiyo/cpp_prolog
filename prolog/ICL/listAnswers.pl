remove_item(_, [], []).
remove_item(E, [E|T], L):- remove_item(E, T, L).
remove_item(E, [H|T], [H|T2]):- E \= H, remove_item(E, T, T2).

drop_items(L, 0, L).
drop_items([H|T], N, X):-
  N > 0,
  New is N - 1,
  drop_items(T, New, X).


more_drop([], L2, []).
more_drop([H|T], L2, [H|T2]):-
  \+(member(H, L2)),
  more_drop(T, L2, T2).

more_drop([H|T], L2, T2):-
  member(H, L2),
  more_drop(T, L2, T2).

drop_more_items(L, N, NewL):-
  drop_more_items(L, N, NewL, []).

drop_more_items(List, 0, NewL, L2):- more_drop(List, L2, NewL).
drop_more_items([H|T], N, NewL, T2):-
  N > 0,
  New is N - 1,
  drop_more_items(T, New, NewL, [H|T2]).

count([], []).
count([X|T], [(X,C)|T1]):-
	appears(X, [X|T], C),
	remove_item(X, [X|T], L),
	count(L, T1).

appears(_, [], 0).
appears(E, [E|T], N):-
	appears(E, T, N1),
	N is N1 + 1.
appears(E, [X|T], N):-
	E \= X,
	appears(E, T, N).
