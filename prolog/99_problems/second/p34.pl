is_prime(2).
is_prime(3).

is_prime(P):-
  integer(P),
  P > 3,
  P mod 2 =\= 0,
  \+(has_factor(P, 3)).

has_factor(N,L):- N mod L =:= 0.
has_factor(N,L):-
  L * L < N,
  L2 is L + 2,
  has_factor(N, L2).

phi(M, Res):-
  prime_list(M, List),
  length(List, Res).

prime_list(0, []).
prime_list(N, [N|T]):-
  N > 0,
  is_prime(N),
  New is N - 1,
  prime_list(New, T).

prime_list(N, T):-
  N > 0,
  \+(is_prime(N)),
  New is N - 1,
  prime_list(New, T).
