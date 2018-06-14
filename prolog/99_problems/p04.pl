% Answer using length/2
% num_element(List, N):- length(List, N).

% Answer using accumulator
num_element([_|T], A, L):- Anew is A + 1, num_element(T, Anew, L).
num_element([], A, A).

% This does not work
num_element2([], 0).
num_element2([_|L], N):- num_element2(L, N1), N1 is N + 1.
