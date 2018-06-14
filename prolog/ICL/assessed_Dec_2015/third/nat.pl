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

cadvs(L):- cadvs([], L).
cadvs(Acc, Acc):- Acc \= [].

cadvs(Acc,L):-
  Acc == [],
  adverb([A]),
  cadvs([A], L).

cadvs(Acc,L):-
  length(Acc, Len),
  Len > 0,
  \+(member(and, Acc)),
  adverb([A]),
  \+(member(A, Acc)),
  cadvs([A, and |Acc], L).

cadvs(Acc,L):-
  length(Acc, Len),
  Len > 0,
  member(and, Acc),
  adverb([A]),
  \+(member(A, Acc)),
  cadvs([A, ',' |Acc], L).
