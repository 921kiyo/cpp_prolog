arc(a,b,1).
arc(c,f,1).
arc(f,e,1).
arc(b,c,1).
arc(d,f,1).
arc(b,d,1).
arc(c,e,1).

path_length(X,Y):- path_length(X,Y,0).
path_length(X,Y,3).
path_length(X,Y, A):-
  A < 3,
  arc(X,Z,L),
  NewA is A + L,
  path_length(Z,Y, NewA).
