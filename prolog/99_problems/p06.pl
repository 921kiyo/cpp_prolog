pali(X):- checkPalindrome(X,[]).

checkPalindrome(L,L).
checkPalindrome([_|L], L).
checkPalindrome([H|T], T2):- checkPalindrome(T, [H|T2]).
