add_poly([],[], Answer).

add_poly([(C1,I)|Rest1],[(C2,I)|Rest2], Answer):-
    C is C1+C2,
    add_poly(Rest1, Rest2, [(C,I)|Answer]).

% add_poly([(C1,I1)|Rest1],[(C2,I2)|Rest2], Answer):-
%     add_poly(Rest1, Rest2, [(C1,I1),(C2,I2)|Answer]).

add_poly([(C1,I1)|Rest1],A, Answer):-
    add_poly(Rest1, A, [(C1,I1)|Answer]).

add_poly(A,[(C2,I2)|Rest], Answer):-
    add_poly(A, Rest, [(C2,I2)|Answer]).