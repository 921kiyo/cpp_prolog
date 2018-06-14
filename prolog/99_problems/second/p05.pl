% rev(L, Rev):- rev(L, [], Rev).
% rev([], A, A).
%
% rev([H|T1], T2, Rev):-
%   rev(T1, [H|T2], Rev).

rev([], []).
rev([H|T], Rev):-
  rev(T, RevT),
  append(RevT, [H], Rev).
