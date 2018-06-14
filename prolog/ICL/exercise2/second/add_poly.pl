add_poly([], [], []).
add_poly([(C1,I)|T1],[(C2,I)|T2], [(C3, I)|Res]):-
  C3 is C1 + C2,
  add_poly(T1, T2, Res).
