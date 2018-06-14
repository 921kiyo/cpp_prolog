pack([],[]).
pack([H1|T1], [H2|T2]):-
  transfer(H1,T1,Ys, H2),
  pack(Ys,T2).

transfer(X, [], [], [X]).
transfer(X, [H|T], [H|T], [X]):- X \= H.

transfer(X,[X|T], Y, [X|T2]):-
  transfer(X,T,Y,T2).
