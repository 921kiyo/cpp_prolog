is_prime(2).
is_prime(3).
is_prime(N):-
  N > 3,
  NewN is N - 1,
  non_divisible(N, NewN).

non_divisible(N, 1).
non_divisible(N, NN):-
  M is N mod NN,
  M \= 0,
  NN > 1,
  NewNN is NN - 1,
  non_divisible(N, NewNN).
