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
% adverb([absolutely]).

% Question a
count_sentence(T,C):-
  sentence(T),
  C = 1.
count_sentence(T,C):-
  append(S, [and|Rest], T),
  count_sentences(Rest, NewC),
  C is NewC + 1.

% Question 2

noun_phrase_better([A,Word]):-
  noun([Word]),
  atom_chars(Word, [H|T]),
  is_vowel(H),
  (A = an; A = the).

noun_phrase_better([A,Word]):-
  noun([Word]),
  atom_chars(Word, [H|T]),
  \+(is_vowel(H)),
  (A = a; A = the).

is_vowel(L):-
  member(L, [a,e,i,o,u]).

% Question 3 a

% cadvs([X]):-
%   adverb([X]).
%
% cadvs([X1, and ,X2]):-
%   adverb([X1]),
%   adverb([X2]),
%   X1 \= X2.
%
% cadvs([X1, ',', X2, and ,X3]):-
%   adverb([X1]),
%   adverb([X2]),
%   adverb([X3]),
%   X1 \= X2,
%   X1 \= X3,
%   X2 \= X3.

cadvs(L):-
  length(L, Len),
  Len > 5,
  append(FirstList,[BeforeLast, and, Last],L),
  adverb([BeforeLast]),
  adverb([Last]),
  BeforeLast \= Last,
  check_repetition(FirstList, [BeforeLast, Last]).

check_repetition([], _).
check_repetition([H,','|T], Used):-
  \+(member(H, Used)),
  check_repetition(T, [H|Used]).
