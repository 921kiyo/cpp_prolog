goundterm(Term):- 
    atomic(Term).

goundterm(Term):-
    nonvar(Term),
    Term =.. [_|Args],
    goundterms(Args).

groundterms([]).
groundterms([H|T]):-
    groundterms(H),
    groundterms(T).