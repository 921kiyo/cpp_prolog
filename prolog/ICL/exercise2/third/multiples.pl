multiples(N, Res):- multiples(N,Res, []).
multiples(0, Res, Res).
multiples(N, Res, T):-
  N > 0,
  list_recursion(N, H),
  NewN is N - 1,
  multiples(NewN, Res, [H|T]).

list_recursion(N,H):- list_recursion(N,H,N,[]).
list_recursion(N, X, 0, X).
list_recursion(N, X, C, T):-
  C > 0,
  H is N*C,
  NewC is C - 1,
  list_recursion(N, X, NewC, [H|T]).
