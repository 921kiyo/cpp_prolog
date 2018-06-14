delete([], []).
delete([X], [X]).
delete([T1,_|H1], [T1|H2]):-
    delete(H1,H2).