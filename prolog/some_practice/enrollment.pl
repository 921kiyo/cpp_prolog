enrolment(L, Student, Degree):-
	member((Degree, Ls), L),
	member(Student, Ls).