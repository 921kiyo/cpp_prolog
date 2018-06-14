% add_poly(L1, L2, Answer):- add_poly(L1,L2,Answer, []).

% add_poly([], [], X, X).

add_poly(L1, L2, Answer):-
  poli_sort(L1,SL1),
  poli_sort(L2,SL2),

% add_poly([(N1,P1)|T1], [(N2,P2)|T2], X, T3):-
%   add_poly(T1, T2, X, [()])
