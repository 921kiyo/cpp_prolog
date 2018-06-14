dupli([], N, []).
dupli([H|T1], N, T2):-
  get_dupli(H,N,List),
  append(List, NewT2, T2),
  dupli(T1,N,NewT2).

get_dupli(W,0,[]).
get_dupli(W,N,[W|T]):-
  N > 0,
  New is N - 1,
  get_dupli(W,New,T).
