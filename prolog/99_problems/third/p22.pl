range(End, End, [End]).
range(X, End, [X|T]):-
  X < End,
  NewX is X + 1,
  range(NewX, End, T).
