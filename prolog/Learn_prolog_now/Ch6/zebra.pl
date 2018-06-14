sublist( [], _ ).
sublist( [X|XS], [X|XSS] ) :- sublist( XS, XSS ).
sublist( [X|XS], [_|XSS] ) :- sublist( [X|XS], XSS ).

zebra(N):-
    Street = [House1, House2, House3],
    member(house(red,_,_), Street),
    member(house(blue,_,_), Street),
    member(house(green,_,_), Street),
    member(house(red,english,_), Street),
    member(house(_,spanish,jaguar), Street),
    sublist([house(_,_,snail), house(_,japanese,_)], Street),
    sublist([house(blue,_,_), house(_,_,snail)], Street),
    member(house(_,N,zebra), Street).
