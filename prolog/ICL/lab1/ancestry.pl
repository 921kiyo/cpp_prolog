%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% Unassessed Laboratory
%%%%% Question 1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%% Question a
% parent(X,Y): X is the parent of Y
parent(alex, ben).
parent(alex, charlie).
parent(ben, daniel).
parent(ben, emily).
parent(ben, freya).

parent(daniel, harry).
parent(daniel, isabelle).

parent(emily, jack).
parent(emily, katie).
parent(emily, lily).

parent(charlie, georgia).

parent(georgia, nathalie).
parent(georgia, max).

%%% Question b
% sibling(X,Y): X and Y are siblings

sibling(X, Y):- parent(Z, X), parent(Z,Y).
% sibling(X,Y):- sibling(Y,X), !.

%%% Question c
% grandparent(X,Y): X is the grand-parent of Y

grandparent(X,Y):- parent(X, Z), parent(Z,Y).

%%% Question d
% ancestor(X,Y): X is an ancestor of Y

ancestor(X,Y):- parent(X,Y).
ancestor(X,Y):- parent(X,Z), ancestor(Z,Y).

%%% Question e
% descendant(X,Y): X is a descendant of Y

descendant(X,Y):- ancestor(Y,X).

%%% Question f
% cousin(X,Y): X and Y are 1st degree cousins

cousin(X,Y):- grandparent(Z,X), grandparent(Z,Y), \+(sibling(X,Y)), \+(X=Y).

%%% Question g
% cousin2(N, X, Y): X and Y are Nth degree cousins

cousin2(1,X,Y):- cousin(X,Y).
% cousin2(N,X,Y) :- ..., New is N-1,
cousin2(N,X,Y):- parent(A, X), parent(B,Y), cousin2(New,A,B), N is New +1.

%%% Question h
% cousin3(N, M, X, Y): X and Y are Nth degree cousins, M times removed

cousin3(N,M,X,Y):- x_older(N,M,X,Y).
cousin3(N,M,X,Y):- x_younger(N,M,X,Y).

x_older(N,1,X,Y) :-
  parent(A,Y),
  cousin2(N, X, A).

% When X is older than Y
% x_older(N,0,X,Y):-
%   cousin2(N,X,Y).
x_older(N,M,X,Y):-
  parent(A,Y),
  print(older_recursive),
  print(A),
  nl,
  x_older(N,New, X,A),
  M is New+1.

% When X is younger than Y
x_younger(N,0,X,Y):-
  cousin2(N, X,Y).
x_younger(N,M,X,Y):-
  print(younger_recursive),
  nl,
  parent(A,X),
  x_younger(N,New, A,Y),
  M is New+1.
