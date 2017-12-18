hasdups([]).

hasdups([H|T]):- member(H, T), hasdups(T).

% checkdups([], Answer, Answer).
%
% checkdups([Head|Tail], Answer, Count):-
%     checkdups(Tail, Answer, NewCount),
%     member(Head, Tail),
%     NewCount is Count + 1.

% checkdups([Head|Tail], Count):-
%     not(member(Head, Tail)),
%     checkdups(Tail, Count).
