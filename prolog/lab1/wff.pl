%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% Unassessed Laboratory
%%%%% Question 2
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%% Question a
% wff(F): F is a well formed formula

% atoms(X):- atom(X).

wff(X,Y):- atom(X), atom(Y).
wff((X)):- atom(X).
wff(and(X,Y)):- wff(X,Y).
wff(or(X,Y)):- wff(X,Y).
wff(imp(X,Y)):- wff(X,Y).
wff(neg(X)):- wff(X).

%%% Question b
% t_value(P, V): proposition P evaluates to V (true or false)


%%% Question c
% fml_eval(F, V): formula F evaluates to V (true or false)
