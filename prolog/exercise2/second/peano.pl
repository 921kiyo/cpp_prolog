hasdups(List):- check_dups(List, List, []).
check_dups(_, [], List).
