% split(T, 1, [], T).
% split([H|T1], C, [H|T2], L2):-
%   C > 1,
%   NewC is C - 1,
%   split(T1,NewC, T2, L2).
%
% remove_at(X, List, N, R):-
%   split(List, N, L1, [X|L2]),
%   append(L1,L2,R).

remove_at(H, [H|T], 1, T).
remove_at(X, [H|T1], N, [H|T2]):-
  N > 1,
  New is N - 1,
  remove_at(X,T1,New, T2).
