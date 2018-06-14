% compile the Prison Database

:- ensure_loaded(prisonDB).

forall(C1,C2) :-
	\+ (C1, \+ C2).

cell(N) :-
   cells(Cells),
   in_range(1,Cells,N).

in_range(Min, Max, Min):-
  Min =< Max.

in_range(Min, Max, N):-
  Min < Max,
  NewMin is Min + 1,
  in_range(NewMin, Max, N).

% Question b
empty_cell(C):-
	\+(prisoner(_,_,C,_,_,_)).

% Question c
all_female_cell(C):-
  cell(C),
  \+(empty_cell(C)),
  forall(prisoner(_,N,C,_,_,_),female_name(N)).

% Part d
female_prisoners(N):-
	setof((FN,LN), FN^LN^Cell^Crime^Sentence^ToServe^(prisoner(FN, LN,Cell,Crime,Sentence,ToServe), female_name(LN)), List),
	length(List, N).

% Part e
cell_occupancy(C,N):-
  cell(C),
  findall((A,B), prisoner(A,B,C,_,_,_), List),
  length(List, N).

% Pert f
fullest_cell(C1):-
  cell_occupancy(C1, N1),
  \+((cell_occupancy(C2, N2), C1\=C2, N2>N1)).

% Pert g
worst_psychopath(S,F,Crime,T):-
  psychopath(S,F),
  prisoner(S,F,_, Crime,T,_),
  \+((psychopath(S1,F1), prisoner(S1,F1,_,_,T1,_),T1 > T)).
