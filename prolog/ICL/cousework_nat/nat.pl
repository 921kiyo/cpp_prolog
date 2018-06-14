%%%%% Natural Language Program

sentence(S) :-
	noun_phrase(NP),
	verb_phrase(VP),
	append(NP, VP, S).

noun_phrase(NP) :-
	article(A),
	noun(N),
	append(A, N, NP).

verb_phrase(V) :-
	verb(V).
verb_phrase(VP) :-
	verb(V),
	noun_phrase(NP),
	append(V, NP, VP).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* The required predicates and argument positions are:

	a.  conj(Text)
	b.  encode(Text, EncodedText)
	c.  same_actor(Text)

*/

% The base case for the recursion
% and when there is only one sentence
conj(Text):- sentence(Text).

% Recursion predicate to split Text into a sentence and rest by "and",
% and check if each sentence before "and" is a valid sentence
conj(Text):-
	sentence(S),
	append(S, [and], Rest),
	append(Rest, Last, Text),
	conj(Last).

% Question b

% Encodes into "a" or "d", depending on whether the first character is animate
encode_first_letter(Letter, a):-
	animate(AnimateList),
	member(Letter, AnimateList).

encode_first_letter(Letter, d):-
	animate(AnimateList),
	\+(member(Letter, AnimateList)).

% Encodes into "l" or "s" depending of the length of the noun
encode_second_letter(List, l):-
	length(List, Length),
	Length > 3.

encode_second_letter(List, s):-
	length(List, Length),
	Length =< 3.

% Encodes each word into three characters according to
% the rule specified
do_encode(Text, Encoded):-
	atom_chars(Text, List),
	append([H], _, List),
	encode_first_letter(Text, First),
	encode_second_letter(List, Second),
	atom_chars(Encoded, [First, Second ,H]).

% Loop through each word, and if a word is noun,
% call do_encode and store an encoded word to the list. Otherwise,
% store the letter as is.
encode([], []).
encode([H|T1],[Encoded|T2]):-
	noun([H]),
	do_encode(H, Encoded),
	encode(T1, T2).
encode([H|T1],[H|T2]):-
	\+(noun([H])),
	encode(T1, T2).

same_actor(Text):-
  get_actor(Text, List),
  setof(Actor, member(Actor, List) ,List2),
  length(List2, 1).

get_actor([_], []).
get_actor([Actor, Verb|Rest1], [Actor|Rest2]):-
  noun([Actor]),
  verb([Verb]),
  get_actor(Rest1, Rest2).

get_actor([A, B|Rest1], Rest2):-
  \+((noun([A]), verb([B]))),
  get_actor([B|Rest1], Rest2).
