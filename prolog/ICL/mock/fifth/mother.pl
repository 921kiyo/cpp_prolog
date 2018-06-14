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

ecb(M):-
  child_mother(X, M),
  age(X, Age),
  Age =< 14.

ecb(M):-
  \+(employed(M)),
  child_mother(X, M),
  age(X, Age),
  Age > 14,
  Age =< 16.

mother_of_the_youngest(M1):-
  child_mother(C1,M1),
  age(C1,Age1),
  \+((child_mother(C2,_),age(C2, Age2), Age2 < Age1)),
  \+((child_mother(C3, M3), age(C3, Age1), M3 @> M1)).

sorting([E], [E]).
sorting([H|T], SL):-
  sorting(T, NewSL),
  selection_sort(H, NewSL, SL).

selection_sort(H, [], [H]).
selection_sort(E, [H|T], [E|[H|T]]):-
  E =< H.

selection_sort(E, [H|T], [H|T2]):-
  E > H,
  selection_sort(E, T, T2).
