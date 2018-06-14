flatten(List, FL):- flatten(List, [] ,FL).

flatten([], Acc,Acc).

flatten(X,Acc,[X|Acc]):-
  X\=[],
  X\=[_|_].

flatten([H|T], Acc, Res):-
  flatten(T, Acc, NewAcc),
  flatten(H,NewAcc,Res).
