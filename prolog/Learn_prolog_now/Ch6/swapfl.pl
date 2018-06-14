swapfl([H1|T1], [H2|T2]):- append(Middle, [H2], T1), append(Middle, [H1], T2).
% swapfl([First, Last], [Last, First]).
% swapfl([First, Next|L1], [Last, Next|L2]):- swapfl([First|L1], [Last|L2]).
