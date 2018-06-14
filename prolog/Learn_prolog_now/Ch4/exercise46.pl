twice([], []).
twice([H|T], [H, H|List]):- twice(T, List).