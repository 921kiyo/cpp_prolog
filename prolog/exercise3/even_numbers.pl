even_numbers([], []).
even_numbers([_], []).
even_numbers([_, X |Rest1], [X|Rest2]):-
    even_numbers(Rest1, Rest2).