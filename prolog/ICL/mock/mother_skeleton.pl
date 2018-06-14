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


mother_of_the_youngest(M):-
  child_mother(Child, M),
  age(Child, X),
  % There is no childres who is younger than X
  \+ (age(Child2, Y), Y < X),
  % There is no mother whos name is alphabetically smaller than M
  \+ (child_mother(Child3, M2), age(Child3, X), M2 @< M).


mothers_of_young2(LM) :-
    setof(M, Child^X^(child_mother(Child, M), age(Child, X), X =< 10), LM).

make_list(M):-
  child_mother(C,M),
  age(C, Age),
  Age =< 10.

mothers_of_young(LM):-
    setof(M,make_list(M), LM).

sorting([], []).
sorting([H|T], [H, H2|T2]):-
  H < H2,
  sorting(T, [H2|T2]).

sorting([H|T], [H, H2|T2]):-
  H < H2,
  sorting(T, [H2|T2]).

merge(L1, L2, L):-
  append(L1, L2, List),
  sorting(List, L).

findElement(1, [H|T], H).
findElement(N, [H|T], X):-
  N > 1,
  New is N - 1,
  findElement(New, T, X).
