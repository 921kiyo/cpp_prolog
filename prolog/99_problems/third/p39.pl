is_prime(2).
is_prime(3).
is_prime(N):-
  N > 3,
  non_divisible(N).

non_divisible(N):-
  New is N - 1,
  non_divisible(N,New).

non_divisible(N,1).
non_divisible(N1, N2):-
  N2 > 1,
  M is N1 mod N2,
  M \= 0,
  New2 is N2 - 1,
  non_divisible(N1, New2).

prime_range(Upper, Upper, [Upper]):- is_prime(Upper).
prime_range(Upper, Upper, []):- \+(is_prime(Upper)).

prime_range(L, U, [L|T]):-
  L < U,
  is_prime(L),
  NewL is L + 1,
  prime_range(NewL, U, T).

prime_range(L, U, T):-
  L < U,
  \+(is_prime(L)),
  NewL is L + 1,
  prime_range(NewL, U, T).
