pack([],[]).
pack([H|T1], [Rest|T2]):-
  transfer(H,[H|T1], NewList, Rest),
  pack(NewList,T2).

transfer(_, [], [], []).
transfer(E, [H|T],[H|T], []):-
  E \= H.

transfer(E, [E|T1],List, [E|T2]):-
  transfer(E, T1, List, T2).
