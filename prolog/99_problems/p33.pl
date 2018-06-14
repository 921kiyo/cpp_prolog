
coprime(A,B):- 
    NewA is A - 1,
    A mod NewA =:= 0,
    B mod NewA =:= 0,
    coprime(NewA, B).

coprime(A,B):- 
    A mod 1 =:= 0,
    B mod 1 =:= 0.