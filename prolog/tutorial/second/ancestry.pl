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

% Question b
sibling(X,Y):- parent(P, X), parent(P,Y), X\=Y.

% Question c
grandparent(X,Y):- parent(X, Z), parent(Z,Y).

% d
ancestor(X,Y):- parent(X,Y).
ancestor(X,Y):-
  parent(X,Z),
  ancestor(Z,Y).

% question e
descendant(X,Y):- ancestor(Y,X).

% Question f
cousin(X,Y):- grandparent(P, X), grandparent(P,Y), \+sibling(X,Y), X\=Y.

% Question g
% Base case
cousin2(1,X,Y):-cousin(X,Y).

cousin2(N,X,Y):-
  parent(X1, X),
  parent(Y1, Y),
  cousin2(New, X1,Y1),
  N is New + 1.

cousin3(N, 0, X, Y):- cousin2(N,X,Y).

cousin3(N, M, X, Y):-
  \+(ancestor(X,Y)),
  parent(X1, X),
  cousin3(N,NewM,X1,Y),
  M is NewM + 1.

cousin3(N, M, X, Y):-
  ancestor(X,Y),
  parent(Y1, Y),
  cousin3(N,NewM,X,Y1),
  M is NewM + 1.
