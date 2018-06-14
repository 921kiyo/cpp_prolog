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

direct(S1, S2, Line, Route):-
	route(Line, Stations),
	member(S1, Stations),
	member(S2, Stations),
	get_route(S1,S2,Stations, Route).

get_route(S1, S2, Stations, Route):-
	append(_, [S1|Rest], Stations),
	append(Route1,[S2|_], Rest),
	append([S1|Route1], [S2], Route).

get_route(S1, S2, Stations, Route):-
	rev(Stations, RevStations),
	append(_, [S1|Rest], RevStations),
	append(Route1,[S2|_], Rest),
	append([S1|Route1], [S2], Route).

changes([], []).
changes(A, [_]):- changes(A, []).
changes([(Line1, Line2, S2)|T1], [(Line1, Stations1),(Line2, Stations2) |T2]):-
	direct(S1, S2,Line1, Stations1),
	direct(S2, S3,Line2, Stations2),
	Line1 \= Line2,
	changes(T1, [(Line2, Stations2) | T2]).

changes(T1, [(Line1, Stations1), (Line1, Stations2) |T2]):-
	direct(S1, S2,Line1, Stations1),
	direct(S2, S3,Line1, Stations2),
	append([S2],Rest, Stations2),
	append(Stations1, Rest, Stations3),
	changes(T1, [(Line1, Stations3 )|T2]).

noReps(PR):-
	findall(Line, member((Line, Stations),PR),LineList),
	no_dup(LineList).

no_dup(List):- no_dup(List, []).

no_dup([], _).
no_dup([H|T], T2):-
	\+(member(H, T2)),
	no_dup(T, [H|T2]).


jp(S1, S2, [(Line, Route)]):-
	direct2(S1, S2, Line, Route).

jp(S1,S2, [(Line, Route)|PR]):-
	direct2(S1, Dest, Line, Route),
	jp(Dest, S2, PR), noReps([(Line, Route)|PR]).

direct2(S1, S2, Line, Route):-
	route(Line, Stations),
	member(S1, Stations),
	member(S2, Stations),
	get_route2(S1,S2,Stations, Route).

get_route2(S1, S2, Stations, Route):-
	append(_, [S1|Rest], Stations),
	append(Route1,[S2|_], Rest),
	append([S1|Route1], [S2], Route).
