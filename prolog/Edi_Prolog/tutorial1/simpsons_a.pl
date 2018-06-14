
person(X):- male(X).
person(X):- female(X).

employer(X):- employs(X, _).

parent(X, Y):- father(X, Y).
parent(X, Y):- mother(X, Y).

parent_disj(X, Y):- father(X, Y); mother(X, Y).

grandparent(X, Y):- parent(X, Y), parent(Y, Z).

sibling(X, Y):- parent(Z, X), parent(Z, Y).

classmate(X, Y):- teaches(Z, X), teaches(Z, Y).

% Question 5 Goal ordering
aunt(Aunt, Child):- female(Aunt), parent_disj(Parent, Child), sibling(Parent, Aunt).