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

% Question 2
get_list([Name, is, a, double, agent|T1], Name).

get_list([H1|T1], T2):-
  get_list(T1, T2).

agents(M, DM, List):-
  decode(M,DM),
  findall(Agent, get_list(DM, Agent), List).

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

% Question 5
