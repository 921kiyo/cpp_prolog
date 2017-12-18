% Q1.a
mysort(L,SL):- setof(I, member(I,L), SL).

% Q1.b
% Tail recursive
rev1(L, RevL):- revAcc(L,RevL,[]).
revAcc([],Acc,Acc).
revAcc([H|T1],RevL, Acc):- revAcc(T1, RevL, [H|Acc]).

% Non-tail recursive

rev2([],[]).
rev2([H|T],R1):- rev2(T,R2), append(R2,[H], R1).

% Q1.c
followedBy(X,Y,[X,Y|_]).
followedBy(X,Y,[_|H]):- followedBy(X,Y,H).

% Q1.d
nextTo(X,Y,[X,Y|_]).
nextTo(X,Y,[Y,X|_]).
nextTo(X,Y,[_|H]):- nextTo(X,Y,H).

% Q1.e
sumList(L,S):- calcTotal(L,S,0).
calcTotal([],S,S).

calcTotal([H|T],R,S):- New is S + H, calcTotal(T,R,New).

% Q1.f
last(E,[E]).
last(E,[_|T]):- last(E,T).

% 2.a
edge(a,b).
edge(a,e).
edge(b,c).
edge(e,f).
edge(f,c).
edge(c,d).
edge(f,d).

% 2.b
path(X,Y):- edge(X,Y).
path(X,Y):- edge(X,Z), path(Z,Y).

% 2.c
path2(X,Y,P):-
  edge(X,P),
  edge(P,Y).

path2(X,Y,P):-
  edge(X,P),
  path2(P,Y,_).

path2(X,Y,P):- edge(X,Z), path2(Z,Y,P).


% 3
max(E,[H|T]):- acc_max(E,[H|T],H).
acc_max(Max,[],Max).
acc_max(E,[H|T], Max):- H > Max, acc_max(E,T,H).
acc_max(E,[H|T], Max):- H =< Max, acc_max(E,T,Max).

% 4
flatten([], Acc, Acc).
flatten(X, Acc, [X|Acc]):-
  X\=[],
  X\=[_|_].

flatten([X|Xs], Acc, Result):-
  flatten(Xs, Acc, NewAcc),
  flatten(X,NewAcc, Result).

flatten(List, Flat):- flatten(List, [], Flat).


max_of_all(E,Ls):- flatten(Ls, Flat), max(E, Flat).
