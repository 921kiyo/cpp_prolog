male(bob).
male(charlie).
male(david).
female(alice).
female(eve).

neighbour(alice, bob).
neighbour(bob, charlie).
neighbour(charlie, david).
neighbour(david, eve).

% Doctor, teacher, dentist, layer, firefigher

% Question a
neighbour_sym(X,Y):- neighbour(X,Y); neighbour(Y,X).    

% Bob is not the doctor
% The teacher and lawyer are both male.
% The firefighter and laywer are neighbours
% The dentist has a female neighbour

% Question b
% test(Doc, Tea, Den, Law, Fir):-
%     \+(Doc=bob),
%     male(Tea),
%     male(Law),
%     neighbour_sym(Fir,Law),
%     neighbour_sym(Den, X),
%     female(X).
test(Doc,Tea,Den,Law,Fir) :-
	\+(Doc=bob),
	male(Fir), male(Tea),
	 neighbour_sym(Fir,Law),
	 neighbour_sym(Den,X), female(X).

% Question c
generate(Doc,Tea,Den,Law,Fir).