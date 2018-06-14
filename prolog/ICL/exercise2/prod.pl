
prod([], 1).
prod([H|T], NewTotal):- 
    prod(T, Total),
    NewTotal is Total * H.
