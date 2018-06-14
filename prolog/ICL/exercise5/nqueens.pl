% Question1
no_attack(List, q(Col1, Row1)):-
  findall(Row, member(q(Col, Row), List), RowList),
  \+(member(Row1, RowList)).

% Question2
template([q(1,_), q(2,_), q(3,_),q(4,_), q(5,_), q(6,_),q(7,_), q(8,_)]).

% queens8([]).
% queens8([q(X,Y)|Rest]):-
%   queens8(Rest),
%   member(Y, [1,2,3,4,5,6,7,8]),
%   no_attack(Rest, q(X,Y)).

queens8([], _).
queens8([q(X,Y)|Rest], Sol):-
  member(Y,[1,2,3,4,5,6,7,8]),
  no_attack(Sol, q(X,Y)),
  queens8(Rest, [q(X,Y)|Sol]).
