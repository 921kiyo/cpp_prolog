% reverse(L, Rev):- reverse(L, [], Rev).
%
% reverse([], R, R).
%
% reverse([H|T], Acc, R):-
%   reverse(T,[H|Acc], R).
%
% compress([H|T], Res):- compress([H|T], [], Temp), reverse(Temp, Res).
%
% compress([H], L, [H|L]).
%
% compress([H, H|T], Acc, Res):-
%   compress([H|T], Acc, Res).
%
% compress([H1, H2|T], Acc, Res):-
%   H1 \= H2,
%   print(H1),
%   nl,
%   compress([H2|T], [H1|Acc], Res).

compress([], []).
compress([X], [X]).
compress([H, H|T], Res):-
  compress([H|T], Res).

compress([H1, H2|T], [H1|Res]):-
  H1 \= H2,
  compress([H2|T], Res).
