palindrome(L):- 
    check_palindrome(L, []).
check_palindrome(L, L).
check_palindrome([_|L], L).
check_palindrome([H|T], LPal):- check_palindrome(T, [H|LPal]).