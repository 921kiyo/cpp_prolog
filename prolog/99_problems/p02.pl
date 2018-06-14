second_last(X1, [X1, X2]).
second_last(X, [H|T]):- second_last(X, T).