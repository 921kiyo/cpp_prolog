my_last(H, [H]).
my_last(X, [H|List]):- my_last(X, List).