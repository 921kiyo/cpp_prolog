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

access_element(0, [H|T], H).
% access_element().
