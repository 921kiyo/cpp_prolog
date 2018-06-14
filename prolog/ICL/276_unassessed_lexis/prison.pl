% compile the Prison Database

:- ensure_loaded(prisonDB).

forall(C1,C2) :-
	\+ (C1, \+ C2).

cell(N) :-
   cells(Cells),
   in_range(1,Cells,N).

% Part a

% in_range(M, M, M).
% in_range(Min, Max, Min):-
% 	NewMin is Min + 1,
% 	in_range(NewMin, Max, NewMin).

% :- use_module(library(between)).
% in_range(Min, Max, N):- between(Min, Max, N).

in_range(Min, Max, Min):-
	Min =< Max.

in_range(Min, Max, N):-
	Min < Max,
	NewMin is Min + 1,
	in_range(NewMin, Max, N).

% Part b
% empty_cell(Cell):-
% 	findall(X, prisoner(X,_,Cell,_,_,_), List),
% 	length(List, Len),
% 	Len == 0.

% Part b Without using findall
empty_cell(C):-
	\+(prisoner(_,_,C,_,_,_)).

% Part c
% check_all_female([]).
% check_all_female([H|T]):-
% 	female_name(H),
% 	check_all_female(T).
%
% all_female_cell(Cell):-
% 	findall(X, (prisoner(_,X,Cell,_,_,_)), List),
% 	check_all_female(List).

% all_female_cell(C):-
% 	cell(C),
% 	\+(empty_cell(C)),
% 	forall(prisoner(_,F,C,_,_,_), female_name(F)).
all_female_cell(C):-
  cell(C),
  \+(empty_cell(C)),
  forall(prisoner(_,N,C,_,_,_),female_name(N)).



% Part d
% female_prisoners(N):-
% 	setof((FN,LN), FN^LN^Cell^Crime^Sentence^ToServe^(prisoner(FN, LN,Cell,Crime,Sentence,ToServe), female_name(LN)), List),
% 	length(List, N).

% Part e
cell_occupancy(C,N):-
	cell(C),
	findall((FN,LN), prisoner(FN,LN,C,_,_,_), List),
	length(List, N).

% Part f
fullest_cell(C):-
	cell_occupancy(C,N),
	\+((cell_occupancy(C2,N2), N2 > N)).

% Part g
worst_psychopath(S,F,Crime,T):-
	psychopath(S,F),
	prisoner(S,F,_,Crime, T, X),
	\+((psychopath(S2,F2),prisoner(S2,F2,_,Crime2, T2, X2), T2 > T)).

% Part h
criminals(Crime,N):-
	crimes(List),
	member(Crime, List),
	findall((FN,FS), prisoner(FN,FS,_,Crime,_,_), List2),
	length(List2, N).
