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

lines(S,L):-
  setof(X, X^S^List^(route(X, List), member(S, List)), L).

lines(S,L):-
  \+(setof(X, X^S^List^(route(X, List), member(S, List)), L1)),
  L = [].

disjointed_lines(Ls):-
	setof((Line1, Line2),
	List1^List2^(route(Line1, List1), route(Line2, List2), Line1 \= Line2, \+((member(X, List1), member(X, List2))), Line1 @< Line2),  Ls).

% direct(S1, S2, Line, Route):-
%   route(Line, List),
%   member(S1, List),
%   member(S2, List),
%   (get_route(S1,S2,List, Route); rev(List, List1), get_route(S1,S2,List1, Route)) .

direct(S1, S2, Line, Route):-
  route(Line, List),
  member(S1, List),
  member(S2, List),
  get_route(S1,S2,List, Route).


get_route(S, S, _, [S]).
get_route(S1, S2, [S1, S|T1], [S1|T2]):-
  get_route(S, S2, [S|T1], T2).

get_route(S1, S2, [S|T1], T2):-
  S1 \= S2,
  get_route(S1, S2, T1, T2).

changes([], [_]).
changes([(Line1, Line2, S)|T1], [(Line1, _),(Line2, [S|Rest])|T2]):-
  Line1 \= Line2,
  changes(T1, [(Line2, [S|Rest])|T2]).

changes(C, [(Line1, T1), (Line1, T2)|T]):-
  changes(C, [(Line1, T2)|T]).

noReps([]).
noReps([(L,_)|T]):-
  noReps(T),
  \+(member((L,_), T)).

% directX(S1, S2, [(Line,Route)]):-
%   route(Line, List),
%   member(S1, List),
%   member(S2, List),
%   get_route(S1,S2,List, Route),
%   length(Route, RLen),
%   RLen > 1.


% jp(S1,S2,[(Line, Route)]):-
%   directX(S1,S2,Line, Route).
%
% jp(S1,S2,[(Line, Route)|T]):-
%   directX(S1,S3,Line, Route),
%   S2 \= S3,
%   jp(S3,S2, T),
%   noReps([(Line, Route)|T]).

% modified direct to include station checking.
directX(S1, S2, [(L, R)]):-
	route(L, Ss),
	member(S1, Ss), member(S2, Ss),
	get_route(S1, S2, Ss, R),
	length(R, Rlen),
	Rlen > 1.

% base case both in same line
jp(S1, S2, [(L, R)]):-
	directX(S1, S2, [(L, R)]).

jp(S1, S2, [(L, R)|T]):-
	directX(S1, S3, [(L, R)]),
	jp(S3, S2, T),
	noReps([(L, R)|T]).
