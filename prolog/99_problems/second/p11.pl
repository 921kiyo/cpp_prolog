pack([], []).
pack([H1|T1], [H2|T2]):-
  transfer(H1, T1, Ys, H2),
  pack(Ys, T2).

transfer(X, [], [], [X]).
transfer(X, [H|T], [H|T], [X]):- X \= H.

transfer(X, [X|T], Ys, [X|T2]):- transfer(X, T, Ys, T2).

encode(List, Res):-
  pack(List, Pack),
  count(Pack, Res).

count([], []).
count([[H|Rest]|T], [[L, H]|T2]):-
  length([H|Rest], L),
  count(T, T2).

encode_modified(List, Res):-
  encode(List, Res1),
  modify(Res1, Res).

modify([], []).
modify([[Count, Letter]|T1],[Letter|T2]):-
  Count == 1,
  modify(T1, T2).

modify([[Count, Letter]|T1],[[Count, Letter]|T2]):-
  Count > 1,
  modify(T1, T2).
