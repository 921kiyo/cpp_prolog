arc(a,b).
arc(c,f).
arc(f,e).
arc(b,c).
arc(d,f).
arc(b,d).
arc(c,e).
% arc(d,a).

path(X,Y,N):- path(X,Y,N,1).
path(X,Y,N,N):-
  arc(X,Y).
path(X,Y,N,C):-
  N \= C,
  NewC is C + 1,
  arc(X,Z),
  path(Z,Y, N, NewC).


path(X,Y):-
  arc(X,Y).

path(X,Y):-
  arc(X,Z),
  path(Z,Y).


% cycle(X):-
%   cycle(X,[]).
% cycle(X,Visited):-
%   member(X,Visited),!.
%
% cycle(X,[X|Visited]):-
%   arc(X,Y),
%   cycle(Y,Visited).
cycle(X):-
    cycle(X,[]).

cycle(C, Visited):-
    member(C, Visited),!.

cycle(C, Visited):-
    arc(C,Next),
    cycle(Next, [C|Visited]).

contains(L1,L2,N):-
  append(A,Half, L1),
  append(L2, _, Half),
  length(A,N1),
  N is N1+1.
