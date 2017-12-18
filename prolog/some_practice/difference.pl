difference([], _, []).

% If not member, keep it!
difference([H|T], List, [H|L]):-
    not(member(H, List)),
    difference(T,List, L).

% If member, just continue
difference([H|T], List, L):-
    member(H, List),
    difference(T,List, L).