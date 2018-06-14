uncompress(H, Res):- uncompress(H, [], Res).
uncompress([0, Letter], Res, Res).

uncompress([Count, Letter], H, Res):-
  Count > 0,
  NewCount is Count - 1,
  uncompress([NewCount, Letter], [Letter|H], Res).

decode(List, Res):- decode(List, [], Res).
decode([], Res, Res).

decode([H|T], List, Res):-
  H \=[_|_],
  append(List, [H],NewList),
  decode(T, NewList, Res).

decode([H|T], List, Res):-
  uncompress(H, Decoded),
  append(List, Decoded,NewList),
  decode(T, NewList, Res).
