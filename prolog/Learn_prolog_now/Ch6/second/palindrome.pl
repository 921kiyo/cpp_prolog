palindrome(L):- palindrome(L, []).

palindrome(A, A).
palindrome([_|A], A).

palindrome([H|T], T2):-
  palindrome(T, [H|T2]).
