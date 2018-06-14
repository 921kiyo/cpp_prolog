prod([], 0).
prod(List, Res):-
  Res \= 0,
  prod(List, Res, 1).

prod([], Sum, Sum).
prod([H|T], Acc, Sum):-
  NewSum is Sum * H,
  prod(T, Acc, NewSum).
