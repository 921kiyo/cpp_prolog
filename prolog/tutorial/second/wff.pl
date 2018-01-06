wff(F):- atom(F).

wff(and(A,B)):-
  wff(A),
  wff(B).

wff(or(A,B)):-
  wff(A),
  wff(B).

wff(imp(A,B)):-
  wff(A),
  wff(B).

wff(neg(A)):-
  wff(A).

t_value(p,true).
t_value(q,false).
t_value(r,true).

neg_table(true, false).
neg_table(false, true).

and_table(true, true, true).
and_table(true, false, false).
and_table(false, true, false).
and_table(false, false, false).

or_table(true, true, true).
or_table(true, false, true).
or_table(false, true, false).
or_table(false, false, false).

imp_table(true, true, true).
imp_table(true, false, false).
imp_table(false, true, true).
imp_table(false, false, true).
