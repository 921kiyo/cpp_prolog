:- dynamic sigmares/2.

sigmares(0,0).

sigma(Number, Sum):-
    sigmares(Number, Sum).

sigma(Number, Total):-
    Number > 0, 
    \+ sigmares(Number, Total),
    NewNumber is Number - 1,
    sigma(NewNumber, SubTotal),
    Total is SubTotal + Number,
    assert(sigmares(Number, Total)).