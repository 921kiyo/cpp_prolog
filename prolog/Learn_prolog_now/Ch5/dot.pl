dot([], [], 0).
dot([H1|T1], [H2|T2], Sum):-
    dot(T1, T2, Rest),
    Sum is Rest + H1*H2.
