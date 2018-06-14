len2([], 0).
len2([H|T], Len):- len2(T, New), Len is New + 1.

len(L, N):- len(L, N, 0).
len([], N, N).
len([_|T], N, Acc):- New is Acc + 1, len(T, N, New).

% len([_|T], L):- len(T, New), L is New + 1.

list_double([], []).
list_double([H|T], [H, H|T2]):- list_double(T, T2).

list_avg(L, Avg):- list_avg(L, Avg, 0, 0).
list_avg([], Avg, Sum, Length):- Avg is Sum/Length.
list_avg([H|T], Avg, AccSum, AccLen):-
  NewSum is AccSum + H,
  NewLen is AccLen + 1,
  list_avg(T, Avg, NewSum, NewLen).


access_element(N, List, X):- access_element(N, List, X, 0).
access_element(N,[X|T], X, N).
access_element(A, [H|T], X, N):-
  New is N + 1,
  access_element(A, T, X, New).

remove(X, [], []).
remove(X, [X|T], R):- remove(X, T, R).
remove(X, [A|T], [A|R]):- remove(X, T, R).

a2b([], []).
a2b([a|T1], [b|T2]):- a2b(T1, T2).
a2b([H|T1], [H|T2]):- a2b(T1, T2).

takeout(H, [H|T], T).
takeout(X, [H|T1], [H|T2]):- takeout(X, T1, T2).

perm([], []).
perm([H|T], Z):- perm(T, W), takeout(H, Z, W).
