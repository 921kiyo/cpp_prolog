:- ensure_leaded(p22), ensure_leaded(p23).

draw_random(N, Range, Result):- range(1, Range, List), rnd_select(List, N, Result).