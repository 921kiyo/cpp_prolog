sentence(S):- noun_phrase(NP), verb_phrase(VP), append(NP, VP, S).

noun_phrase(NP):- article(A), noun(N), append(A, N, NP).

verb_phrase(V):- verb(V).
verb_phrase(VP):- verb(V), noun_phrase(NP), append(V, NP, VP).

% The Lexicon:

article([the]).
article([a]).
article([an]).

noun([grass]).
noun([cow]).
noun([girl]).
noun([boy]).
noun([apple]).
noun([song]).

verb([eats]).
verb([sings]).
verb([chews]).
verb([kicks]).

adverb([slowly]).
adverb([deliberately]).
adverb([merrily]).
adverb([sweetly]).

% Question a
count_sentence(T,C):-
  sentence(T),
  C = 1.
count_sentence(T,C):-
  append(S, [and|Rest], T),
  count_sentences(Rest, NewC),
  C is NewC + 1.

% Questions b
actions(Actor, Text, As):-
  findall(A, (followed_by(Actor, A, Text), A \= and), As).

followed_by(Actor, A, List):-
  append(_, [Actor,A|_], List).

% Question 2
atoms([H|_], W):-
  atom_chars(H, W).

first_vowel([H|_]):-
  member(H, [a,e,i,o,u]).

noun_phrase_better(NP):-
  article(A),
  noun(N),
  atoms(N, W),
  ((first_vowel(W), A = [an]);
  (\+ first_vowel(W), A = [a]);
  (A = [the])),
  append(A, N, NP).

% Question 3
cadvs(L):-
  cadvs([], L).

cadvs(L,L):-
  L \= [].

cadvs(X,L):-
  length(X, 0),
  adverb(A),
  append(A,X,X2),
  cadvs(X2,L).

cadvs(X,L):-
  length(X, Length),
  Length > 0,
  nonmember(and, X),
  adverb([A]),
  nonmember(A,X),
  append([A], [and], X2),
  append(X2, X, X3),
  cadvs(X3,L).

cadvs(X,L):-
  length(X, Length),
  Length > 0,
  member(and, X),
  adverb([A]),
  nonmember(A,X),
  append([A], [','], X2),
  append(X2, X, X3),
  cadvs(X3,L).

% Q3 c

verb_phrase_better(V):-
  verb(V).

verb_phrase_better(V):-
  verb(X),
  noun_phrase_better(Y),
  append(X, Y, V).

verb_phrase_better(V):-
  cadvs(X),
  verb(Y),
  append(X,Y,V).

verb_phrase_better(V):-
  cadvs(X),
  verb(Y),
  append(X,Y,V1),
  noun_phrase_better(Z),
  append(V1, Z, V).


% Q3 d
sentence_better(S):-
  noun_phrase_better(NPB),
  verb_phrase_better(VPB),
  append(NPB, VPB,S).
