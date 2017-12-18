input1(G1,I1).
input2(G2,I2).
output(G3,O).

andgate(g1x).

fib(Counter, Result):- fib(Counter,Result,0,0,1).
fib(0, Total, Total, F0, F1).

fib(Counter, R, Total, F0, F1):-
  NewCounter is Counter - 1,
  NewTotal is Total + F0, F1,
  NewF0 is F
  fib(NewCounter, R, NewTotal).
