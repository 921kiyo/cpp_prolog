lfsort(List, Sort):- lfsort2(List, Sort).

lfsort2(List, Sort):-
  add_key(List, KList, List),
  keysort(KList, SKList),
  rem_key(SKList, Sort).

add_key([], [], _).
add_key([H|T1], [F-p(H)|T2], List):-
  length(H, Length),
  findall(L, (member(X, List), length(X, L), L == Length), Frequency),
  length(Frequency, F),
  add_key(T1, T2, List).

rem_key([], []).
rem_key([_-p(X)|Xs], [X|Ys]):- rem_key(Xs, Ys).
