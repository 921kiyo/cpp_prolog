% common(L1, L2, []):-
%   \+(setof(X, (member(X, L1), member(X,L2)), I)).
% common(L1, L2, I):-
%   setof(X, (member(X, L1), member(X,L2)), I).
common(L1,L2,I) :-
    findall(X, (member(X,L1),member(X,L2)), List),
    sort(List,I).

process(L1, L2, C,I):-
  findall((Name, Age, Status), (member((Name,Age), L1), member((Name,Age,Status), L2)), C),
  findall((Name, Age, Status), (member((Name, Age, Status), L2), \+(member((Name, Age, Status), C))), I).

drop(L,N,Res):- drop(L,N,Res,N).
drop([], _, [], _).
drop([H|T], N, List1, 1):- drop(T, N, List1, N).

drop([H|T1], N, [H|T2], C):-
  C > 1,
  NewC is C - 1,
  drop(T1, N, T2, NewC).

enrolment(L, Student, Degree):-
  findall(D, (member((D, List), L), member(Student, List)), [Degree]).

student_list(L, Meng, MSc):-
  findall(S, (member((meng, List), L), member(S, List)), Meng),
  findall(S2, (member((msc, List2), L), member(S2, List2)), MSc).
