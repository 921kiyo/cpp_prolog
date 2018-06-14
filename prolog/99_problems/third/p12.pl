uncompress([],[]).
uncompress([X|T1], [X|T2]):-
  X \= [_|_],
  uncompress(T1,T2).

uncompress([[0,W]|T1], T2):-
  uncompress(T1,T2).

uncompress([[C,W]|T1], [W|T2]):-
  C > 0,
  NewC is C - 1,
  uncompress([[NewC,W]|T1] ,T2).
