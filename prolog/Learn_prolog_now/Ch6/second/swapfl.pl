% swapfl([], []).
swapfl([H1, H2], [H2, H1]).
swapfl([H1,H2|T1], [H3,H4|T2]):-
  swapfl([H1|T1], [H3|T2]).
