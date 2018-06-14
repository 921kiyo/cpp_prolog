decode([], []).
decode([bear|T1], [double|T2]):-
  decode(T1,T2).
decode([cub|T1], [agent|T2]):-
  decode(T1,T2).

decode([H|T1], [H|T2]):-
  \+((H == bear; H== cub)),
  decode(T1,T2).

agents(M, DM, List):-
  decode(M, DM),
  find_agent(M, List1),
  sorting(List1, List).

agents(M, DM, []):-
  decode(M, DM),
  \+(find_agent(M, List1)).

find_agent([_,_,_,_], []).
find_agent([X, is, a, bear, cub|T1], [X|T2]):-
  find_agent([is, a, bear, cub|T1], T2).

find_agent([X, A, B, C, D|T1], T2):-
  \+((A == is, B == a, C == bear, D==cub)),
  find_agent([A,B,C,D|T1], T2).

sorting([E], [E]).
sorting([H|T], SL):-
  sorting(T, NewSL),
  selection_sort(H, NewSL, SL).

selection_sort(E, [], [E]).
selection_sort(E, [H|T], [E|[H|T]]):-
  E @< H.
selection_sort(E, [H|T], [H|T2]):-
  E @>= H,
  selection_sort(E, T, T2).

count_word(W,L,C):- count_word(W,L,C,0).
count_word(_, [], C,C).
count_word(W, [W|T], C, Acc):-
  NewAcc is Acc + 1,
  count_word(W, T, C, NewAcc).
count_word(W, [H|T], C, Acc):-
  W \= H,
  count_word(W, T, C, Acc).

count_ag_names(M, AG):-
  agents(M, _, List),
  get_ag(List, M,AG).

get_ag([],M, []).
get_ag([H|T], M,[(H, C)|T2]):-
  count_word(H, M, C),
  get_ag(T, M,T2).

accusation_counts(M, AC):-
  agents(M, _, List),
  find_accusation(List, AC1),
  sort2(AC1, AC).

sort2([E], [E]).
sort2([H|T], SL):-
  sort2(T, NewSL),
  sortsort(H, NewSL, SL).

sortsort(H, [], [H]).
sortsort((Name1, C1), [(Name2, C2)|Rest1], [(Name1, C1)|[(Name2, C2)|Rest2]]):-
  Name1 \= Name2,
  C1 > C2.
sortsort((Name1, C1), [(Name2, C2)|Rest1], [(Name2, C2)|Rest2]):-
  Name1 \= Name2,
  C1 =< C2,
  sortsort((Name1, C1), Rest1, Rest2).

find_accusation(List, AC):- find_accusation(List, AC, []).
find_accusation([], AC, AC).
find_accusation([H|T], AC, Acc):-
  count_word(H, [H|T], C),
  remove_element(H, [H|T], NewT),
  find_accusation(NewT, AC, [(H,C)|Acc]).

remove_element(E, [], []).
remove_element(E, [E|T1], T2):-
  remove_element(E, T1, T2).
remove_element(E, [H|T1], [H|T2]):-
  E \= H,
  remove_element(E, T1, T2).
