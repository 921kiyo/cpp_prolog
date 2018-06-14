arc(a,b).
arc(c,f).
arc(f,e).
arc(b,c).
arc(d,f).
arc(b,d).
arc(c,e).

arc(a,b,1).
arc(c,f,1).
arc(f,e,1).
arc(b,c,1).
arc(d,f,1).
arc(b,d,1).
arc(c,e,1).

path(X,Y, 3).
path(X, Y):-
  arc(X,Z, N),
  path(Y,Z, ).
