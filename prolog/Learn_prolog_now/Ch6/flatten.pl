% Copy from middle Acc to end Acc
flatten([], Acc, Acc).

% X should not be an empty or have more than one element in the list
% Adding the last element 
flatten(X, Acc, [X|Acc]) :-
    X\=[],
    X\=[_|_].


% NewAcc keeps the results without brackets
flatten([X|Xs], Acc, Result) :-
    % For the first few iteration, it just removes [].
    flatten(Xs, Acc, NewAcc),
    flatten(X, NewAcc, Result).

flatten(List,Flat) :- flatten(List,[],Flat).
