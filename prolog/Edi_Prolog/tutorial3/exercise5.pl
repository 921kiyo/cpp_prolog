person(fred).
person(peter).
person(ann).
person(beth).
person(tom).
person(talullah).
age(peter,10).
age(ann,5).
age(beth,10).
age(tom,8).

% Question a
test1(Result):-
    bagof(Person, (person(Person), \+(age(Person, X))), Result).

% Question b
test2(Result):-
    setof(X, Y^(person(X), age(X, Y)), Result).

test3(Result):-
    setof(Y, X^(person(X), age(X, Y)), Result).

% Question c
