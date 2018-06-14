% Question a
% nu(A,B):-
%     \+ A = B.

% Question b
% nu(A,B):- (A=B -> fail; true).

% Question c
nu(A,A):- !, fail.
nu(_,_):- !.
