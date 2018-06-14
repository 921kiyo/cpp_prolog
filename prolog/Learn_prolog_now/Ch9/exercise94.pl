groundterm(Term):- atomic(Term).

groundterm(Term):-
    nonvar(Term),
    functor(Term,_,Arity),
    groundterms(Term,Arity).

groundterms(_,0).

groundterms(ComplexTerm,Arg):-
    Arg > 0,
    arg(Arg, ComplexTerm, Term),
    groundterm(Term),
    NexArg is Arg -1,
    groundterms(ComplexTerm, NextArg).