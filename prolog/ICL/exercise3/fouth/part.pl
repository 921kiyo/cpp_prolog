edge(n,t).
edge(t,p).
edge(p,m).
edge(m,n).
edge(g,b).

connected_parts(X, Res):-
  setof(Y, connected(X, Y), Res).

connected(X,Y):-
  edge(X,Y).
connected(X,Y):-
  edge(X,Z),
  connected(Z,Y).
