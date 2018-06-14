flatten(L, F):- flatten(L, [], F).
flatten([], A, A).

flatten(X, Acc, [X|Acc]):-
  X\=[],
  X\=[_|_].

flatten([X|Xs], Acc, Res):-
  flatten(Xs, Acc, NewAcc),
  flatten(X, NewAcc, Res).
