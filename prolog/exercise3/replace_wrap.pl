% replace_wrap([], []).
% replace_wrap([H|T], [wrap(H)|T1]):-
%     replace_wrap(T,T1).

replace_wrap(L,Res):- findall(L, wrap(L), Res).