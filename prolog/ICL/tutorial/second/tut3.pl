mysort(L, SL):-
  setof(X,member(X,L), SL).

% rev(L,RL):- rev(L,[],RL).
% rev([], R, R).
% rev([H|T1], T2, R):-
%   rev(T1, [H|T2], R).

rev([], []).
rev([H|T1], T2):-
  rev(T1, NewT2),
  append(NewT2, [H],T2).

followedBy(X,Y,[X,Y|_]).

followedBy(X,Y,[X1,Y1|T]):-
  (X==X1,Y==Y1)-> X=X1, Y=Y1;followedBy(X,Y,[Y1|T]).

nextTo(X,Y, L):- append(_,[X,Y|_],L).
nextTo(X,Y, L):- append(_,[Y,X|_],L).

sumList([],0).
sumList([H|T],S):-
  sumList(T,Sum),
  S is Sum + H.

last(E,L):- append(_,[E],L).

edge(a,b).
edge(a,e).
edge(b,c).
edge(e,f).
edge(f,c).
edge(c,d).
edge(f,d).

path(X,Y,[X,Y]):-
  edge(X,Y).

path(X,Y,[X|P]):-
  edge(X,Z),
  path(Z,Y,P).

max(E,[H|T]):- max(E,[H|T],H).
max(E,[],E).

max(E,[H|T],Acc):-
  (H > Acc)->
    max(E,T,H); max(E,T,Acc).

max_of_all(E,Ls):-
  concat(Ls,L),
  max(E,L).

concat(Ls, L):-
  findall(X, (member(List, Ls), member(X,List)), L).
