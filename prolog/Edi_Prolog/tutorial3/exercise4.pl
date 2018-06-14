:- dynamic rotA/2.
rot13(Str, SR):- 
    atom_codes(Str, SL),
    maprot(SL, SL1),
    atom_codes(SR, SL1).

maprot([], []).
maprot([H|T], [HH|TT]):-
    rot(H,HH),
    maprot(T, TT).

rot(C,C1):-
    ( member(C, "abcdefghijklmABCDEFGHIJKLM"), C1 is C+13, !);
    ( member(C, "nopqrstuvwxyzNOPQRSTUVWXYZ"), C1 is C-13, !);
    C1 = C.

buildrot:-
    caesartable(T), 
    assertallpairs(T), 
    assertz(rotA(C,C)).

caesartable(Table):-
    setof((C1,C2), allrot(C1,C2), Table).

allrot(C,C1):-
    ( member(C, "abcdefghijklmABCDEFGHIJKLM"), C1 is C+13, !);
    ( member(C, "nopqrstuvwxyzNOPQRSTUVWXYZ"), C1 is C-13, !).

assertallpairs([]).
assertallpairs([(X,Y)|T]):- assert(rotA(X,Y)), assertallpairs(T).

caesarlist_2([], []).
caesarlist_2([X|L], [Y|M]):- rotA(X,Y), !, caesarlist_2(L, M).

caesar_2(X,Y):-
    atom_codes(X,L),
    caesarlist_2(L,M),
    atom_codes(Y,M).

test:- 
    read(X),
    caesar_2(X,Y),
    nl,
    write(Y),
    nl,
    test.
