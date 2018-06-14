% comb(List, Res):- comb(List, Res, []).
% comb(List, Res, Acc):- sort(Acc, Res).
% comb(L, Res, T):-
%   member(H, L),
%   remove(H, L, NewL),
%   comb(NewL, Res,[H|T]).
%
% remove(E, [E|Rest], Rest).
% remove(E, [H|Rest], [H|Rest1]):-
%   E\=H,
%   remove(E,Rest, Rest1).

comb(_, []).
comb([X|T], [X|Comb]):-
  comb(T, Comb).
comb([_|T], [X|Comb]):-
  comb(T, [X|Comb]).
