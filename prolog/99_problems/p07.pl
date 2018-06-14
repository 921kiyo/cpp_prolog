flatten(List, Flat):- flatten(List, [], Flat).

flatten([], Acc, Acc).
flatten(X, Acc, [X|Acc]):- X\=[], X\=[_|_].
flatten([X|Xs], Acc, Result):-
    flatten(Xs,Acc, NewAcc),
    flatten(X, NewAcc, Result).