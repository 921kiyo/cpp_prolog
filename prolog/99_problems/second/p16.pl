drop(List, C, Res):- drop(List, C, Res, C).

drop([],_, [], _).
drop([H|T], C, Res, 1):- drop(T,C,Res,C).

drop([H|T1], C, [H|T2], Count):-
  Count > 1,
  NewC is Count - 1,
  drop(T1, C, T2, NewC).
