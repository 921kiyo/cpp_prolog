once_member1(E, List):- once_member1(E,List, []).

once_member1(X, [X|_], Appeared):-
  \+(member(X, Appeared)).

once_member1(X, [H|List], A):-
  once_member1(X, List, [H|A]).


once_member2(E, List):- once_member2(E,List, []).

once_member2(X, [X|_], Appeared).

once_member2(X, [H|List], A):-
  once_member2(X, List, [H|A]).
