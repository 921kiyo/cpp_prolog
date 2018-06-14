lsort(List, Sort):- llsort(List, Sort).

llsort(InList, OutList):-
  add_key(InList, KList),
  keysort(KList, SKList),
  rem_key(SKList, OutList).


add_key([], []).
add_key([X|Xs], [L-p(X)|Ys]):-
  length(X,L),
  add_key(Xs, Ys).


% add_key([], [], _).
% add_key([X|Xs], [L-p(X)|Ys], asc):-
%   !,
%   length(X,L),
%   add_key(Xs, Ys, asc).

% add_key([X|Xs], [L-p(X)|Ys], desc):-
%   length(X,L1),
%   L is -L1,
%   print(L),
%   nl,
%   add_key(Xs, Ys, desc).

rem_key([], []).
rem_key([_-p(X)|Xs], [X|Ys]):- rem_key(Xs, Ys).
