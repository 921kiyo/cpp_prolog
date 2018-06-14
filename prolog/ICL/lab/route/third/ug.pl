%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% predefined facts and predicate

route(green, [a,b,c,d,e,f]).
route(blue, [g,b,c,h,i,j]).
route(silver, [f,i,k,m]).
route(red, [w,v,e,i,m,n]).
route(yellow, [p, q, r]).

 %  rev(+L1, -L2) means L2 is the list L1 reversed.
rev(L, R) :-
	tr_rev(L, [], R).
tr_rev([], R, R).
tr_rev([H|T], Acc, R) :-
	tr_rev(T, [H|Acc], R).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/*	The required predicates and argument positions are:
	a.	lines(+Station, ?Lines)
	b.	disjointed_lines(-Lines)
	c.	direct(+S1, +S2, ?Line, ?Route)
	d.	changes(?C, +PR)
	e.	noReps(+PR)
	f.	jp(+S1, +S2, -PR)   --- optional
	*/

lines(Station, Lines):-
	findall(Line, (route(Line, List), member(Station, List)), Lines1),
  insertion_sort(Lines1, Lines).

insertion_sort([], []).
insertion_sort([H|T], SL):-
	insertion_sort(T, EL),
	insert_sort(H, EL, SL).

insert_sort(E,[],[E]).
insert_sort(E, L, [E|L]):-
	L = [H|T],
	E @=< H.

insert_sort(E, [H|T], [H|T2]):-
	E @> H,
	insert_sort(E, T, T2).

disjointed_lines(Ls):-
	setof((Line1, Line2),
	List1^List2^(route(Line1, List1), route(Line2, List2), Line1 \= Line2, \+((member(X, List1), member(X, List2))), Line1 @< Line2),  Ls).

direct(S1,S2, Line, Route):-
	route(Line, Stations),
	find_route(S1,S2, Stations, Route).

direct(S1,S2, Line, Route):-
	route(Line, Stations),
	rev(Stations, Stations2),
	find_route(S1,S2, Stations2, Route).

find_route(S, S, _, [S]).

find_route(S1,S2,[S1, Next|T1], [S1|T2]):-
	find_route(Next, S2, [Next|T1], T2).

find_route(S1,S2,[H|T1], T2):-
	S1 \= H,
	find_route(S1, S2, T1, T2).

changes([(L1, L2, H)],[(L1, _), (L2, [H|Rest])]).
changes([(L1, L2, S)|T], [(L1,_), (L2, [H|Rest])| T2]):-
  L1 \= L2,
	changes(T, [(L2, [H|Rest])| T2]).

changes(T, [(L1,_), (L1, Rest)| T2]):-
 	changes(T, [(L1, Rest)| T2]).

noReps(PR):-
  noReps(PR, []).

noReps([], _).
noReps([(H,_)|T], T2):-
  \+(member(H, T2)),
  noReps(T, [H|T2]).
