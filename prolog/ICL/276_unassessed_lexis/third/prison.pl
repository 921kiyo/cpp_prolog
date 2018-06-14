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

empty_cell(C):-
	\+(prisoner(_,_,C,_,_,_)).

all_female_cell(C):-
	cell(C),
	\+(empty_cell(C)),
	forall(prisoner(_,N2,C,_,_,_), female_name(N2)).
