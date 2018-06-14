% rot13:  only for mode (+,?) 

rot13(Str, SR) :-
	atom_codes(Str,SL),
	maprot(SL, SL1),
	atom_codes(SR,SL1).

maprot([],[]).
maprot([H|T],[HH|TT]) :- rot(H,HH),
	                 maprot(T,TT).
 
rot(C, C1) :-
    (   member(C, "abcdefghijklmABCDEFGHIJKLM"), C1 is C+13, ! )
    ; (	member(C, "nopqrstuvwxyzNOPQRSTUVWXYZ"), C1 is C-13, ! )
    ; C1 = C.

% My answer below
translate :- read(X),
	     rot13(X,Y),
	     nl,
	     write(Y),
	     nl,
	     translate.