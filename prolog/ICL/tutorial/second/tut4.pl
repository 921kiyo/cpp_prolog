article([the], singular).
article([the], plural).
article([a], singular).
article([an], singular).

noun([boy], singular).
noun([apple], singular).
noun([song], singular).
noun([boys], plural).
noun([apples], plural).
noun([songs], plural).

verb([eats], singular).
verb([sings], singular).
verb([eat], plural).
verb([sing], plural).

sentence(S):-
  noun_phrase(X, C),
  verb_phrase(Y, C),
  append(X,Y,S).

noun_phrase(S,C):-
  article([X],C),
  noun([Y],C),
  atom_chars(Y, [H|Rest]),
  (member(H, [a,e,i,o,u])->member(X,[an,the]);member(X,[a,the])),
  append([X], [Y],S).
% noun_phrase(S,C):-
%   article(X,C),
%   noun(Y,C),
%   append(X, Y,S).

verb_phrase(S,C):-
  verb(X,C),
  noun_phrase(Y,_),
  append(X,Y,S).

verb_phrase(S,C):-
  verb(S,C).
