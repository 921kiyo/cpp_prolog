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

deadEnd(N):-
  arc(_, N),
  \+(arc(N, _)).

hub(N):-
  arc(N, X),
  findall(Y, (arc(Y, N); arc(N, Y)), L),
  length(L, Length),
  Length >= 3.

hub(N):-
  arc(X, N),
  findall(Y, (arc(Y, N); arc(N, Y)), L),
  length(L, Length),
  Length >= 3.

hubs(H):- setof(N, hub(N), H).


node(X):- arc(X,Y); arc(Y, X).

ideal(X):-
  node(X),
  \+ (node(Y), X \= Y, \+ path(X, Y)).

path(X,Y):-
  arc(X,Y).

path(X,Y):-
  arc(X,Z),
  path(Z,Y).

ppath(N1, N2, [N1]).
ppath(N1, N2, [N1, N2]):- arc(N1, N2).
ppath(N1, N2, [H|Rest]):- arc(N1, X), ppath(X, N2, Rest).

shorter(N1, N2, P):- length(P, L), ppath(X, Y, P1), length(P1, L1), L1 < L.

shortest_path(N1, N2, P):- ppath(N1, N2, P), \+ shorter(N1, N2, P).


% An E in L1 is repeated in L1 at most the number of times it is repeated in L2
% The order of the elements in L1 matches their order in L2
subList([], L2).
subList([H|T1], [H|T2]):- subList(T1, T2).
subList([H1|T1], [H2|T2]):-
  subList([H1|T1], T2),
  H1 \= H2.


cart([], _, []).
cart(_, [], []).
car(L1, L2, P):-findall((X, Y), (member(X, L1), member(Y, L2)), P).
