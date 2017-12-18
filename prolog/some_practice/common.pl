% no repeated elements
common(List1, List2, I):- findall(X, (member(X, List1), member(X, List2)), List), sort(List, I).
