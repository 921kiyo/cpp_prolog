contains(List, SubList, N ):-
    append(Rest,Sub, List), % Suffix
    append(SubList, _, Sub), % Prefix
    length([_|Rest],N).
