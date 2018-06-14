combination(0,_,[]).
combination(K,L,[X|Xs]):-
  K > 0,
  el(X,L,R),
  % print(R),
  % nl,
  K1 is K -1,
  combination(K1, R, Xs).

el(X,[X|L],L).
el(X,[_|L],R):- print(L), nl, el(X,L,R).
