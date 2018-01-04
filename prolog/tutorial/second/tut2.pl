xorgate(g1).
xorgate(g2).
andgate(g3).
andgate(g4).
orgate(g5).

input1(g1,1).
input2(g1,0).

input1(g2,X):- output(g1,X).
input2(g2,1).

input1(g3,X):- output(g1, X).
input2(g3,1).

input1(g4,1).
input2(g4,0).

input1(g5,X):- output(g3,X).
input2(g5,X):- output(g4,X).

output(G,X):-
  andgate(G),
  input1(G,I1),
  input2(G,I2),
  andresult(I1,I2,X).

output(G,X):-
  orgate(G),
  input1(G,I1),
  input2(G,I2),
  orresult(I1,I2,X).

output(G,X):-
  xorgate(G),
  input1(G,I1),
  input2(G,I2),
  xorresult(I1,I2,X).

andresult(1,1,1).
andresult(0,X,0).
andresult(X,0,0).

orresult(1,X,1).
orresult(X,1,1).
orresult(0,0,0).

orresult(1,X,1).
orresult(X,1,1).
orresult(0,0,0).

xorresult(X,X,0).
xorresult(X,Y,1):- X\=Y.

% Question 2

fib(1,1).
fib(2,1).
fib(N,R):-
  N > 2,
  New1 is N - 1,
  New2 is N - 2,
  fib(New1, NewR1),
  fib(New2, NewR2),
  R is NewR1 + NewR2.
