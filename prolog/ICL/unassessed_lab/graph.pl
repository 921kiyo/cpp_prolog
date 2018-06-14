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

% Question 1
deadEnd(N):-
    arc(_, N),
    \+ arc(N, _).

% Question 2
is_hubs(N):-
    (arc(N, X); arc(X,N)),
    (arc(N, Z); arc(Z,N)),
    (arc(N, Y); arc(Y,N)),
    X \= Y, X \= Z,Y \= Z, Z \= Y.

hubs(H):-
    setof(N, is_hubs(N), H).

% Question 3
ideal(N):-
    arc(N, H),
