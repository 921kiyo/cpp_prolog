drop(List, N, Res):- drop(List, N, Res, N).
drop([],_,[],_).
drop([H|T], N, Res, 1):-
  drop(T, N, Res, N).
drop([H|T1], N, [H|T2], C):-
  C > 1,
  NewC is C - 1,
  drop(T1,N,T2,NewC).
