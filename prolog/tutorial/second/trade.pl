sells(usa, grain, japan).
sells(S, P, B) :-  produces(S, P), needs(B, P).

produces(oman, oil).
produces(iraq, oil).
produces(japan, computers).
produces(germany, cars).
produces(france, iron).

needs(germany, iron).
needs(britain, cars).
needs(japan, cars).

% Question 4
needs(britain, coal).
needs(japan, coal).
needs(japan, diamonds).

% Question 2
needs(C, computers):- produces(C,_).
needs(C, computers):- sells(C,_,_).
% needs(_, computers).

needs(C, oil) :- needs(C, cars).

% Question 1
bilateral_traders(X,Z):-
    sells(X,_,Z),
    sells(Z,_,X),
    X \= Z.
% X and Z have not been instantiated before sells/1 is used.
% bilateral_traders(X,Z):-
%     X \= Z,
%     sells(X,_,Z),
%     sells(Z,_,X).

% Question 3
country(japan).
country(britain).
country(germany).
country(france).


% Question 5
nat_res(france, coal).
nat_res(britain, coal).
nat_res(south_africa, diamonds).

% Questionj 6
ce(france, coal).
ce(south_africa, diamonds).

% Question 8

mines(C,I):- nat_res(C,I), ce(C,I).
exports(C1,I,C2):- (produces(C1,I); mines(C1,I)), needs(C2,I).
in_competition(C1,C2,I):-
  exports(C1,I,_),
  exports(C2,I,_),
  C1 \= C2.

lower_price(I):-
  in_competition(C1,C2,I).
