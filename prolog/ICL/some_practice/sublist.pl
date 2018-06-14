subList([], List).
subList([H|T], List):- member(H, List), subList(T, List).
