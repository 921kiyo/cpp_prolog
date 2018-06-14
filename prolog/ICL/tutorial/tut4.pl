% s(Z):- np(X),vp(Y), append(X,Y,Z).
% np(Z) :- article(X), n(Y), append(X,Y,Z).
% vp(Z) :- v(X), np(Y), append(X,Y,Z).
%
% article([the]).
% article([an]).
% article([a]).
%
% n([boy]).
% n([apple]).
% n([song]).
% n([cow]).
% n([grass]).
%
% v([eats]).
% v([sings]).

s --> np, vp.
np --> article, n.
vp --> v, np.

article --> [the].
article --> [an].
article --> [a].

n --> [boy].
n --> [apple].
n --> [song].
n --> [cow].
n --> [grass].

v --> [eats].
v --> [sings].
