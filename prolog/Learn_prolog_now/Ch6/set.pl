:- use_module(library(lists)).

set(InList, OutList):- set(InList, [], OutList).
set([],Acc,Acc).
set([H|Tail],Acc,OutList) :- member(H,Acc), set(Tail,Acc,OutList).
set([H|Tail],Acc,OutList) :- set(Tail,[H|Acc],OutList).
set([H|Tail],OutList) :- set(Tail,[H],OutList).
