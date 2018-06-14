dupli([], []).
dupli([H|T], [H,H|T1]):- dupli(T, T1).