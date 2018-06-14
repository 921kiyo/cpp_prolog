swap(leaf(X), leaf(X)).
swap(tree(B1, B2), tree(B2Swapped, B1Swapped)):-
    swap(B1, B1Swapped),
    swap(B2, B2Swapped).