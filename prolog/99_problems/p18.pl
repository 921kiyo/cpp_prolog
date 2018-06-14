slice([X|_], 1, 1, [X]).

% Keep from I to Kth elements
slice([X|Xs], 1, K, [X|Ys]):-
    K > 1,
    K1 is K - 1,
    slice(Xs,1, K1, Ys).

% Remove the first I elements
slice([_|Xs], I,K,Ys):-
    I > 1, 
    I1 is I - 1,
    K1 is K - 1,
    slice(Xs, I1, K1, Ys).