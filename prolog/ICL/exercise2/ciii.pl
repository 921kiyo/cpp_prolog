arc(a,b).
arc(c,f).
arc(f,e).
arc(b,c).
arc(d,f).
arc(b,d).
arc(c,e).

cycle(X):-
    cycle(X,[]).

cycle(C, Visited):-
    member(C, Visited),!.

cycle(C, Visited):-
    arc(C,Next),
    cycle(Next, [C|Visited]).