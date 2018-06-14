range(Y, Y, [Y]).
range(X, Y, [X|L]):-
  X =< Y,
  NewX is X + 1,
  range(NewX,Y,L).
