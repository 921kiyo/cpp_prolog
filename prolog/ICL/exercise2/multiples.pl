helper(N, Res):- helper(N, Res, [], N, 1).

helper(_, Res, Res, 0, _).

helper(Index, R, T , N, Y):-
  N > 0,
  Mul is Index * N,
  NewY is Y + 1,
  NewN is N - 1,
  helper(Index, R, [Mul|T],NewN, NewY).



multiples(N, R):- multiples(N, R, 1).

multiples(0, _, _).

multiples(N, T, Acc):-
  helper(N, Result),
  N > 0,
  New is N - 1,
  NewAcc is Acc + 1,
  multiples(New, [Result|T],NewAcc).

% multiples(0, []).
%
% multiples(N, [[1]|T]):-
%     N > 0,
%     New is N -1,
%     multiples(New, T).
