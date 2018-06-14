subset([], []).
subset([X|Xs], [X|Ys]):- subset(Xs,Ys).
subset(X, [_|Ys]):- subset(X, Ys).