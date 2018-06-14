termtype(Term, number):- number(Term).
termtype(Term, atom):- atom(Term).
termtype(Term, variable):- var(Term).
termtype(Term, nonvar):- nonvar(Term).
termtype(Term, simpleterm):- atomic(Term).
termtype(Term, complexterm):- nonvar(Term), functor(Term, _, A), A>0.
termtype(Term, term):- termtype(Term, simpleterm).
termtype(Term, term):- termtype(Term, complexterm).
