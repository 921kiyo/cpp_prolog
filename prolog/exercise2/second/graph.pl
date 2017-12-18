arc(a,b,1).
arc(b,a,1).
arc(f,e,1).
arc(b,c,1).
arc(d,f,1).
arc(b,d,1).
arc(c,e,1).

% cycle(X):-
%   cycle(X, []).
%
% cycle(X,Visited):-
%   member(X, Visited), !.
%
% cycle(X, Visited):-
%   arc(X, Next),
%   cycle(Next, [X|Visited]).


path(X):- path(X,f,3).

path(_,f,0).

path(X,Y, N):-
  N > 0,
  arc(X,Z,A),
  print(Z),
  nl,
  New is N - A,
  path(Z,Y, New).
