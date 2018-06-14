s(s(NP, VP)) --> np(NP, X, subject), vp(VP, X).

np(np(DET, N), X, _) --> det(DET, X), n(N, X).
np(np(PRO), X, Y) --> pro(PRO, X,Y).

vp(vp(V,NP), X) --> v(V,X), np(NP, _, object).
vp(vp(V), X) --> v(V,X).

det(det(DET), X) --> [DET], {lex(DET, det, X)}.

n(n(N), X) --> [N], {lex(N,n,X)}.

pro(pro(PRO), X, Y) --> [PRO], {lex(PRO, pro, X,Y)}.

v(v(V), X) --> [V], {lex(V,v,X)}.

lex(he, pro, singular, subject).
lex(she, pro, singular, subject).
lex(they, pro, plural, subject).
lex(him, pro, singular, subject).
lex(her, pro, singular, subject).
lex(them, pro, plural, subject).

lex(the, det, _).
lex(a, det, singular).

lex(man, n, singular).
lex(woman, n, singular).
lex(men, n, plural).
lex(women, n, plural).

lex(shoots, v, singular).
lex(shoot, v, plural).