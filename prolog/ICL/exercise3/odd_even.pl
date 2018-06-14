odd_even([], [], []).
odd_even([H], [H|Rest], Other):- odd_even([], Rest, Other).
odd_even([H1, H2|T1], [H1|T2], [H2|T3]):- odd_even(T1,T2,T3).