pack([],[]).
pack([H1|T1], [Pack|T2]):-
  transfer(H1,[H1|T1], Pack, NewList),
  print(NewList),nl,
  pack(NewList, T2).

transfer(W,[],[], [W]).
transfer(W, [W1|T1],[W1|T1], [W]):- W \= W1.

transfer(W, [W|T1], T2, [W|T2]):-
  transfer(W, T1, T2, T2).
