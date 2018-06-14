:- use_module(library(lists)).
my_flatten([Last], [Last]):-
  \+(is_list(Last)).

my_flatten([Last], OutLast):-
  is_list(Last),
  my_flatten(Last, OutLast).

my_flatten([H|T], X):-
  \+(is_list(H)),
  my_flatten(T,OutT),
  append([H], OutT,X).

my_flatten([H|T], X):-
  is_list(H),
  my_flatten(H,OutH),
  my_flatten(T,OutT),
  append(OutH, OutT,X).
