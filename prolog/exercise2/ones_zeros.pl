ones_zeros([]).

ones_zeros([Head|Tail]):-
    Head == 0,
    ones_zeros(Tail).

ones_zeros([Head|Tail]):-
    Head == 1,
    ones_zeros(Tail).