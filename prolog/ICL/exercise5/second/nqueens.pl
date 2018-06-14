no_attack(P, Queen):-
  \+((member(Qx, P),
     attack_pair(Qx, Queen))).

attack_pair(q(X,_), q(X,_)).
attack_pair(q(_,Y), q(_,Y)).
attack_pair(q(X,Y), q(X1,Y1)):-
  Y1 - Y =:= X - X1.

attack_pair(q(X,Y), q(X1,Y1)):-
  Y1 - Y =:= X1 - X.

template([q(1,_), q(2,_), q(3,_),q(4,_), q(5,_), q(6,_),q(7,_), q(8,_)]).

queens8([]).
queens8([q(X,Y)|Rest]):-
  queens8(Rest),
  member(Y, [1,2,3,4,5,6,7,8]),
  no_attack(Rest, q(X,Y)).

question3(N):-
  template(X),
  findall(X, queens8(X), List),
  length(List, N).
