concat([], L2, L2).

concat([H1|T1], L2, [H1|T3]):-
  concat(T1,L2,T3).
