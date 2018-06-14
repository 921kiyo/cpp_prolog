:-use_module(library(lists)).
set(InList, OutList):- set(InList, OutList, []).
set([], R, R).

set([H|T], Out, T2):- member(H, T2), set(T, Out, T2).
set([H|T], Out, [H|T2]):- \+(member(H, T2)), set(T, Out, T2).
