% % Find max - non-tail recursion
% find_max([X], X).
% find_max([H|T], H):-
%   find_max(T, Max),
%   Max < H.
%
% find_max([H|T], Max):-
%   find_max(T, Max),
%   Max >= H.
%
%
%
% merge(L1, L2, L):-
%   append(L1, L2, List),
%   insertion_sort(List, L).
%
% insertion_sort([E], [E]).
% insertion_sort([H|T],SL):-
%   insertion_sort(T, ST),
%   insert_sort(H,ST,SL).
%
% insert_sort(E, [], [E]).
% insert_sort(E, L, [E|L]):-
%   L = [H|T],
%   E =< H.
%
% insert_sort(E,[H|T], [H|ET]):-
%   E > H,
%   insert_sort(E, T, ET).
%
% count([], []).
% count([H|T1], [(H, C)|T2]):-
%   counting(H, [H|T1], C),
%   remove(H, [H|T1], NewList),
%   count(NewList,T2).
%
% counting(E, L, C):- counting(E,L,C,0).
% counting(E,[],C,C).
%
% counting(E,[E|T], C, Acc):-
%   NewAcc is Acc + 1,
%   counting(E,T,C,NewAcc).
%
% counting(E,[H|T], C, Acc):-
%   E\=H,
%   counting(E,T,C,Acc).
%
% remove(E, [], []).
% remove(E, [E|T1], T2):-
%   remove(E,T1,T2).
% remove(E, [H|T1], [H|T2]):-
%   E \= H,
%   remove(E,T1,T2).
%
%
% merge2(L1, L2, M):-
%   append(L1, L2, M1),
%   cadvs(M1, M).
%
% cadvs([E], [E]).
% cadvs([H|T], SL):-
%   cadvs(T, New),
%   sele_sort(H,New, SL).
%
% sele_sort(E, [], [E]).
% sele_sort(E, [H|T], [E|[H|T]]):-
%   E < H.
%
% sele_sort(E, [H|T1], [H|T2]):-
%   E >= H,
%   sele_sort(E, T1, T2).
%
% rev(L, Rev):- rev(L,Rev,[]).
%
% rev([], R, R).
%
% rev([H|T1], Rev, T2):-
%   rev(T1, Rev, [H|T2]).
%
% min([H|T], Min):- min([H|T], H, Min).
% min([], M, M).
% min([H|T1], Acc, Min):-
%   (H < Acc)-> min(T1, H, Min); min(T1, Acc, Min).

sorting([E], [E]).
sorting([H|T], SL):-
  sorting(T, NewSL),
  selection_sort(H, NewSL, SL).

selection_sort(E, [], [E]).
selection_sort(E, [H|T], [E|[H|T]]):-
  E < H.

selection_sort(E, [H|T1], [H|T2]):-
  E >= H,
  selection_sort(E, T1, T2).
