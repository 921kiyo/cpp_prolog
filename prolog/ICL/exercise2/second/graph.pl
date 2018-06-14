arc(a,b).
arc(b,a).
arc(f,e).
arc(b,c).
arc(d,f).
arc(b,d).
arc(c,e).

% path(X, Y, via(no)):- arc(X,Y).
% path(X, Y, via(Z, Via)):- arc(X,Z), path(Z,Y, via(Via)).

path_via(X,Z, via(no)):- arc(X,Z).
path_via(X,Z, via(Y, Via)):-
    arc(X,Y), path_via(Y, Z, Via).
