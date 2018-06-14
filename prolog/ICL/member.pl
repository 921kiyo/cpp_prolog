belongs_to(X,[X|_]).

belongs_to(X, [H|T]):-
  belongs_to(X,T).
