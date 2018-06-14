multiples(N, L):- multiples(N,L,[]).
multiples(0,L,L).
multiples(N, L, T):-
  N > 0,
  get_list(N, List),
  New is N - 1,
  multiples(New,L, [List|T]).

get_list(N, List):- get_list(N, List, 1).
get_list(N, [H], N):- H is N*N.
get_list(N, [H|T], C):-
    N\=C,
    NewC is C + 1,
    H is C*N,
    get_list(N, T, NewC).
