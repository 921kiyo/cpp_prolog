arc(a,b).
arc(c,f).
arc(f,e).
arc(b,c).
arc(d,f).
arc(b,d).
arc(c,e).

path(X,Y, via(0)):- arc(X,Y).

path(X,Y, via(Z, A)):- arc(X,Z), path(Z,Y, A).
