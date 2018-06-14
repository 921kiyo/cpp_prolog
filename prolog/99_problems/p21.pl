insert_at(A, [H|T], 2, [H,A|T]).
insert_at(A, [H|T], N, [H|T2]):- N > 2, NewN is N -1, insert_at(A, T, NewN, T2).