piece_of_code:-
    open('hogwart.txt', write, Stream),
    tab(Stream, 6),
    write(Stream, gryffindor),
    nl(Stream),
    write(Stream,hufflepuf),
    tab(Stream, 6),
    write(Stream, revanclaw),
    nl(Stream),
    tab(Stream, 6),
    write(Stream, slytherin),
    close(Stream).