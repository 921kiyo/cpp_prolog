difference([], _, []).
difference([H|T1], L, [H|T2]):-
  \+(member(H, L)),
  difference(T1, L, T2).

difference([H|T1], L, T2):-
  member(H, L),
  difference(T1, L, T2).

common(L1, L2, I):-
  setof(X, (member(X, L1), member(X, L2)), I).

delete([], []).
delete([H1, H2| T1], [H1|T2]):-
  delete(T1, T2).


process(L1, L2, C, I):-
  setof((Name, Age, I), (member((Name, Age),L1), member((Name, Age, I), L2)), C),
  setof((Name, Age, I),
      (member((Name, Age, I),L2),
      \+member((Name1, Age1, I), C)), I).


split([], 0, [], []).
split(T, 0, [], T).
split([H|T], N, [H|T2], X):-
  N > 0,
  New is N - 1,
  split(T, New, T2, X).

drop(L, N, Result):- drop(L, N, Result, 1).
drop([], _, [], _).
drop([H|T], N, T2, Acc):-
  0 =:= mod(Acc,N),
  NewAcc is Acc + 1,
  drop(T, N, T2, NewAcc).

drop([H|T], N, [H|T2], Acc):-
  0 =\= mod(Acc,N),
  NewAcc is Acc + 1,
  drop(T, N, T2, NewAcc).

enrolment(L, Student, Degree):-
  member((Degree, List), L),
  member(Student, List).


student_list(List, Meng, MSc):-
  findall(Student, (member((msc, L1), List), member(Student, L1)), MSc),
  findall(S, (member((meng,L2), List), member(S, L2)), Meng).
