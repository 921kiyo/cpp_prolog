all_members([], List).
all_members([H|T], List):- member(H, List), all_members(T, List).