dupli(L,N,Res):-dupli(L,N,Res,N).

dupli([],_,[],_).
dupli([H|T1],N,Res,0):- dupli(T1,N,Res,N).

dupli([H|T1], N, [H|T2], C):-
  C > 0,
  NewC is C - 1,
  dupli([H|T1], N, T2, NewC).
