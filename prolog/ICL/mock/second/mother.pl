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


% Question 1

ecb(M):-
  child_mother(C,M),
  age(C, Age),
  (Age =< 14; \+(employed(M)), Age >= 14, Age =< 16).


mothers_of_young(LM):-
  setof(M, Age^C^M^(child_mother(C,M), age(C, Age), Age =< 10), LM).


merge(L1, L2, L):-
  append(L1, L2, List),
  insert_sort(List, L).

insert_sorted(E,[],[E]).
insert_sorted(E,L,EL) :- L=[H|T], E=<H, EL=[E|L].
insert_sorted(E,L,EL) :- L=[H|T], E>H, EL=[H|ET] ,insert_sorted(E,T,ET).
% insertion sort recursion
insertion_sort([E],[E]).
insertion_sort(L,SL) :- L=[H|T], insertion_sort(T,ST), insert_sorted(H,ST,SL).



findElement(1, [H|T], H).
findElement(N, [H|T], E):-
  N > 1,
  New is N - 1,
  findElement(New, T, E).
