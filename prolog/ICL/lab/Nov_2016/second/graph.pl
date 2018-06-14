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

collect_hubs(N):-
  (arc(N, X); arc(X, N)),
  (arc(N, Y); arc(Y, N)),
  (arc(N, Z); arc(Z, N)),
  X \= Y,
  Y \= Z,
  Z \= X.

hubs(N):-
  setof(X, collect_hubs(X), N).


path(X,Y):-
  arc(X,Y).

path(X,Y):-
  arc(X,Z),
  path(Z,Y).

ideal(N):-
  findall(X, (arc(X,Y); arc(Y,X)), List1),
  setof(X, member(X, List1), List2),
  setof(X, (path(N,X); path(Y,X )), List3),
  print(List3),nl.
