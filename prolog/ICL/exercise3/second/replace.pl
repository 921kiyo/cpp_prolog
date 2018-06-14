replace_wrap([], []).
replace_wrap([H|T], [wrap(H)|T2]):-
  replace_wrap(T, T2).

replace_wrap2(List, Res):-
  findall(wrap(X), (member(X, List)), Res).

even_members([], []).
even_members([_], []).

even_members([H1,H2|T], [H2|T2]):-
  even_members(T, T2).


odd_even_members([], [], []).

odd_even_members([H1,H2|T1], [H2|T2], [H1|T3]):-
  odd_even_members(T1, T2, T3).

odd_even_members([R], A, [R|T]):-
  odd_even_members([], A, T).
