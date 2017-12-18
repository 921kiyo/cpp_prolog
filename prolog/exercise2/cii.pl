arc(a,b,1).
arc(c,f,1).
arc(f,e,1).
arc(b,c,1).
arc(d,f,1).
arc(b,d,1).
arc(c,e,1).

path_length(X,Z,Length):- check_length(X,Z,Length,1).
check_length(X,Z,Length, Length):- arc(X,Z,T).

check_length(X,Z,Answer, Length):- 
    arc(X,Y,L), NewLength is Length + L, check_length(Y,Z,Answer,NewLength).