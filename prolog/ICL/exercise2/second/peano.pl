plus(0, 0, _).

plus(s(X), Y, s(Z)):-
  plus(X,Y,Z).

plus(X, s(Y), s(Z)):-
  plus(X,Y,Z).
