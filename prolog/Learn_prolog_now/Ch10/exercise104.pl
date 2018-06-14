directTrain(saarbruecken, dudweiler) .
directTrain(forbach, saarbruecken) .
directTrain(freyming, forbach) .
directTrain(stAvold, freyming) .
directTrain(fahlquemont, saarbruecken) .
directTrain(metz, fahlquemont) .
directTrain(nancy, metz) .

route(X, Y, L) :- routeAcc(X, Y, [X], L).

routeAcc(X, X, Acc, Acc).

routeAcc(X, Y, Acc, Result) :-
  (directTrain(X, Z); directTrain(Z, X)),
  \+ member(Z, Acc),
  append(Acc, [Z], NewAcc),
  routeAcc(Z, Y, NewAcc, Result).
