dupli(List, C, Res):- dupli(List, C, [], Res).
dupli([], _, R, R).
dupli([H|T], C, L, Res):-
  get_dupli(H, C, List),
  append(L, List, NewList),
  dupli(T, C, NewList, Res).

get_dupli(H, C, List):- get_dupli(H,C,List,[]).
get_dupli(H,0, L,L).
get_dupli(H, C, Res, List):-
  C > 0,
  NewC is C -1,
  get_dupli(H, NewC, Res, [H|List]).
