:-use_module(library(random)).

check_squares:-
  nl, write('Do you want to play?'),
  nl, read(X),
  (X=no -> (write(goodbye), nl, nl);
            random(1,20,Y),
            nl, askabout(Y)).

  askabout(X):-
    write(['what is the square of', X, '?']),
    read(Y),
    Z is X*X,
    (Y is Z-> write(correct), nl;
    write(wrong), tab(4),
    writeMessage(['the square of', X, is, Z])),
    check_squares.
