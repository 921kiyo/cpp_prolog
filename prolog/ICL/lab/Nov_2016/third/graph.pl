arc(a,b).
arc(a,c).
arc(a,d).
arc(b,e).
arc(c,g).
arc(c,f).
arc(d,c).
arc(d,f).
arc(g,e).
arc(g,f).

node(X,Y):-
  (arc(X,Y); arc(Y,X)).

hubs(H):-
  setof(X,
  X^Y1^Y2^Y3^(node(X,Y1),
  node(X,Y2),
  node(X,Y3),
  Y1 \= Y2,
  Y1 \= Y3,
  Y3 \= Y2), H).

path(X,Y):-
  arc(X,Y).
path(X,Y):-
  arc(X,Z),
  path(Z,Y).

node(X):- arc(X,Y); arc(Y, X).

ideal(X):-
  node(X),
  \+ (node(Y), X \= Y, \+ path(X, Y)).

% path(X,Y):-
%   arc(X,Y).
%
% path(X,Y):-
%   arc(X,Z),
%   path(Z,Y).

%%%% 1(iv)   %%%%
ppath(X, X, [X]).
ppath(X, Y, [X,Y]) :-
	arc(X,Y).
ppath(X, Y, [X|Rest]) :-
	arc(X, Z),
	ppath(Z, Y, Rest).

% find a path P
% prove there are no shorter paths
% hence P must be shortest path
shortest_path(X, Y, P):-
	ppath(X, Y, P),
	\+ shorter(X, Y, P).

% shorter succeeds if a shorter path from X, Y
% exists which is less than P
shorter(X, Y, P):-
	length(P, L),
	ppath(X, Y, P1),
	length(P1, L1),
	L1<L.

subList([], _).
subList([H|T], L2):-
  member(H, L2),
  subtract(H, L2, NewL2),
  subList(T, NewL2).

subtract(E, [E|T], T).
subtract(E, [H|T1], T2):-
  E \= H,
  subtract(E, T1, T2).

cart(L1, L2, P):-
  setof((X,Y), (member(X,L1), member(Y, L2)), P).

cart(L1, L2, P):-
  \+(setof((X,Y), (member(X,L1), member(Y, L2)), P)),
  P = [].
