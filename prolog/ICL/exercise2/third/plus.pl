plus(0,0, 0).

plus(s(X), s(Y), s(Z)):-
  plus(X,s(Y), Z).

plus(0, s(Y), s(Z)):-
  plus(0,Y, Z).
