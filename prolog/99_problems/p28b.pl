:- ensure_loaded(p28a).

lfsort(InList, OutList):- lfsort(InList, OutList, asc).
lfsort(InList, OutList, Dir):-
    add_key(InList, KList, desc),
    keysort(KList, SKList),
    pack(SKList, PKList),
    lsort(PKList, SPKList, Dir),
    flatten(SPKList, FKList),
    rem_key(FKList, OutList).

pack([], []).
pack([L-X|Xs], [[L-X|Z]|Zs]):- transf(L-X,Xs,Ys,Z), pack(Ys,Zs).

% transf(L-X,Xs,Ys,Z) Ys is the list that remains from the list Xs
%    when all leading copies of length L are removed and transfed to Z

transf(_, [], [], []).
transf(L-_, [K-Y|Ys], [K-Y|Ys], []):- L \= K.
transf(L-_, [L-X|Xs], Ys, [L-X|Zs]):- transf(L-X, Xs, Ys, Zs).