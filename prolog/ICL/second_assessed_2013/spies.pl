
% Question 1
decode([], []).
decode([H1|T1], [double|T2]):-
  H1 == bear,
  decode(T1, T2).

decode([H1|T1], [agent|T2]):-
  H1 == cub,
  decode(T1, T2).

decode([H1|T1], [H1|T2]):-
  H1 \= bear,
  H1 \= cub,
  decode(T1, T2).

% get_agent([], []).
get_agent([A, is, a, double, agent|T], A).

get_agent([H|T], T2):-
  get_agent(T, T2).

agents(M, DM, List):-
  decode(M, DM),
  findall(X,get_agent(DM, X), List).


count_word(W,L,C):- count_word(W,L,C,0).
count_word(_, [], C,C).
count_word(W, [W|T], C, Acc):-
  NewAcc is Acc + 1,
  count_word(W, T, C, NewAcc).
count_word(W, [H|T], C, Acc):-
  W \= H,
  count_word(W, T, C, Acc).

check([], _, []).
check([H|T], DM, [(H,C)|T2]):-
  count_word(H, DM, C),
  C > 0,
  check(T, DM, T2).

check([H|T], DM, T2):-
  count_word(H, DM, C),
  C == 0,
  check(T, DM, T2).


count_ag_names(M, Res):-
  agents(M, DM, List),
  check(List,DM,Res).

swap([], []).
swap([(H1, H2)|T1], [(H2, H1)|T2]):-
  swap(T1, T2).

decend_order([], []).
decend_order([(Name1, C1),(Name2, C2)|T1],[(Name2, C2),(Name1, C2)|T1] )

  % swap(List, Swap),
  % setof(X, (member(X, Swap)), L1),
  % swap(L1, Sorted).

accusation_counts(M, AC):-
  agents(M, DM, List),
  setof((Name, Count), (member(Name, List),count_word(Name, List, Count)),AC1),
  decend_order(AC1, AC).
