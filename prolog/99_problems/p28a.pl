lsort(InList, OutList):- lsort(InList, OutList, asc).

lsort(InList, OutList, Dir):-
    add_key(InList, KList, Dir),
    keysort(KList, SKList),
    rem_key(SKList, OutList).

add_key([], [], _).
add_key([X|Xs], [L-p(X)|Ys], asc):- !,
    length(X,L), add_key(Xs,Ys,asc).
add_key([X|Xs], [L-p(X)|Ys], desc):-
    length(X,L1), L is -L1, add_key(Xs, Ys, desc).

rem_key([], []).
rem_key([_-p(X)|Xs], [X|Ys]):- rem_key(Xs, Ys).
    