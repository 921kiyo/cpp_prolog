member1(E, L):- append(_,[E|_],L).

set([H|T], Res):- set([H|T], [H], Res).

set([], A, A).

set([H|T], Acc, Res):- member(H, Acc), set(T, Acc, Res).

set([H|T], Acc, Res):- \+(member(H, Acc)), set(T, [H|Acc], Res).
