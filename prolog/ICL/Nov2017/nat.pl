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

conj(Text):-
  sentence(Text).

conj(Text):-
  sentence(S),
  append(S, [and|Rest], Text),
  conj(Rest).


% Question b

get_first(H, a):-
  animate(L), member(H,L).

get_first(H, a):-
  animate(L),
  \+(member(H,L)).

get_second(List, l):-
  length(List, Length),
  Length > 3.

get_second(List, s):-
  length(List, Length),
  Length =< 3.

get_encode(T,ET):-
  atom_chars(T, [H|Rest]),
  get_first(H, First),
  get_second([H|Rest], Second),
  atom_chars(ET, [First, Second, H]).

encode([], []).
encode([H1|T1], [H2|T2]):-
  noun([H1]),
  get_encode(H1, H2),
  encode(T1, T2).

encode([H1|T1], [H1|T2]):-
  \+(noun([H1])),
  encode(T1, T2).

same_actor(T):-
    get_actor(T, As),
    setof(X, member(X, As), L),
    length(L,1).

get_actor([], []).
get_actor([_], []):- get_actor([],[]).
get_actor([X,Y|T1], [X|T2]):-
  noun([X]),
  verb([Y]),
  get_actor(T1,T2).

get_actor([X,Y|T1], T2):-
  \+((noun([X]),verb([Y]))),
  get_actor([Y|T1],T2).
