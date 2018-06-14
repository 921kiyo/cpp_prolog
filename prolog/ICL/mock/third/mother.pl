% child_mother(C, M) means C is a child of mother M.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

child_mother(amy, mary).
child_mother(arthur, mary).
child_mother(angel, jane).
child_mother(anton, rita).
child_mother(alan, rita).
child_mother(axel, susan).
child_mother(ann, tina).


% age(C, A) means C is of age A.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

age(amy, 6).
age(arthur, 15).
age(angel, 16).
age(anton, 4).
age(alan, 8).
age(axel, 16).
age(ann, 4).


% employed(X) means X is employed.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

employed(susan).
employed(rita).

mother_of_the_youngest(M):-
  child_mother(C1, M),
  age(C1,A1),
  \+((age(C2,A2), A2<A1)),
  \+((child_mother(C3, M2), age(C3, A1), M2 @< M)).

insert_sort(E, [], [E]).
insert_sort(E, L, [E|L]):-
  L = [H|T], E =< H.

insert_sort(E, L, [H|EL]):-
  L = [H|T],
  E > H,
  insert_sort(E, T, EL).

insertion_sort([E], [E]).
insertion_sort([H|T], SL):-
  insertion_sort(T, ST),
  insert_sort(H, ST, SL).
