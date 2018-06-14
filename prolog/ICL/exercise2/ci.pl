arc(a,b).
arc(c,f).
arc(f,e).
arc(b,c).
arc(d,f).
arc(b,d).
arc(c,e).

path_via(X,Z, via(no)):- arc(X,Z).
path_via(X,Z, via(Y, Via)):-
    arc(X,Y), path_via(Y, Z, Via).
