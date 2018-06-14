unifiable([],_,[]).
unifiable([X|Xs],Term,[X|Result]):-
    \+(\+ X=Term),
    unifiable(Xs,Term,Result).

unifiable([X|Xs],Term,Result):-
    \+ X=Term,
    unifiable(Xs,Term,Result).