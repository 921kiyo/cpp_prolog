% the students in Hogwarts
student(hp, 'Harry James Potter', gryffindor).
student(hg, 'Hermione Jean Granger', gryffindor).
student(rw, 'Ronald Weasley', gryffindor).
student(ll, 'Luna Lovegood', ravenclaw).
student(cc, 'Cho Chang', ravenclaw).
student(tb, 'Terry Boot', ravenclaw).
student(ha, 'Hannah Abbott', hufflepuff).
student(cd, 'Cedric Diggory', hufflepuff).
student(nt, 'Nymphadora Tonks',hufflepuff).
student(dm, 'Draco Malfoy', slytherin).
student(gg, 'Gregory Goyle', slytherin).
student(vc, 'Vincent Crabbe', slytherin).
student(kk, 'Kiyo', slytherin).

% the teachers in Hogwarts
teacher(ad, 'Albus Percival Wulfric Brian Dumbledore').
teacher(ff, 'Filius Flitwick').
teacher(rh, 'Rubeus Hagrid').
teacher(gl, 'Gilderoy Lockhart').
teacher(rl, 'Remus John Lupin').
teacher(mm, 'Minerva McGonagall').
teacher(qq, 'Quirinus Quirrell').
teacher(ss, 'Severus Snape').
teacher(ps, 'Pomona Sprout').
teacher(st, 'Sibyll Patricia Trelawney').
teacher(mh, 'Madam Hooch').
teacher(as, 'Aurora Sinistra').
teacher(cub, 'Cuthbert Binns').
teacher(bb, 'Bathsheba Babbling').
teacher(sv, 'Septima Vector').
teacher(chb, 'Charity Burbage').
teacher(wt, 'Wilkie Twycross').

% compulsory courses for the MSc in Magic
compCourse(astro, 'Astronomy', as).
compCourse(charms, 'Charms', ff).
compCourse(defence, 'Defence against the Dark Arts', qq).
compCourse(fly, 'Flying', mh).
compCourse(herb, 'Herbology', ps).
compCourse(history, 'History of Magic', cub).
compCourse(potions, 'Potions', ss).
compCourse(trans, 'Transfiguration', mm).

% optional courses for the MSc in Magic
optCourse(runes, 'Study of Ancient Runes', bb).
optCourse(arith, 'Arithmancy', sv).
optCourse(muggle, 'Muggle Studies', chb).
optCourse(creatures, 'Care of Magical Creatures', rh).
optCourse(div, 'Divination', st).
optCourse(app, 'Apparition', wt).
optCourse(choir, 'Frog Choir', ff).
optCourse(quid, 'Quidditch', mh).


enrolled_opt(kk, runes).
enrolled_opt(kk, arith).
enrolled_opt(kk, muggle).

enrolled_opt(hp, arith).
enrolled_opt(hp, quid).
enrolled_opt(hp, div).

enrolled_opt(hg, runes).
enrolled_opt(hg, div).
enrolled_opt(hg, muggle).
enrolled_opt(hg, creatures).
enrolled_opt(hg, arith).
enrolled_opt(hg, app).

enrolled_opt(rw, quid).
enrolled_opt(rw, runes).
enrolled_opt(rw, div).

enrolled_opt(ll, creatures).
enrolled_opt(ll, div).
enrolled_opt(ll, runes).

% enrolled_opt(cc, creatures).
enrolled_opt(cc, div).
enrolled_opt(cc, quid).

enrolled_opt(tb, runes).
enrolled_opt(tb, muggle).
enrolled_opt(tb, app).

enrolled_opt(ha, runes).
enrolled_opt(ha, arith).
% enrolled_opt(ha, creatures).

enrolled_opt(cd, quid).
enrolled_opt(cd, muggle).
enrolled_opt(cd, div).

enrolled_opt(nt, runes).
enrolled_opt(nt, arith).
% enrolled_opt(nt, creatures).

enrolled_opt(dm, quid).
enrolled_opt(dm, arith).
enrolled_opt(dm, app).

enrolled_opt(gg, runes).
enrolled_opt(gg, div).
enrolled_opt(gg, arith).

enrolled_opt(vc, muggle).
enrolled_opt(vc, arith).
% enrolled_opt(vc, creatures).

enrolled_opt(la, arith).
enrolled_opt(la, quid).
enrolled_opt(la, div).

% Question 3
enrolled(SID, SCN):-
  enrolled_opt(SID, SCN).
enrolled(SID, SCN):-
  student(SID, _, _),
  compCourse(SCN, _, _).

% Question 4
teaches(TN, SCN):-
  compCourse(SCN, _, X),
  teacher(X, TN).

teaches(TN, SCN):-
  optCourse(SCN, _, X),
  teacher(X, TN).

% Question 5

% Could have used enrolled
taughtBy(SN, TN):-
  student(SID, SN, _),
  enrolled_opt(SID, CID),
  optCourse(CID,_, TID),
  teacher(TID, TN).

taughtBy(SN, TN):-
  student(SID, SN, _),
  compCourse(CID,_, TID),
  teacher(TID, TN).

takesOption(SN, CN):-
  optCourse(CID, CN, _),
  enrolled_opt(SID, CID),
  student(SID, SN, _).

takesAllOptions(SN, OptCourses):-
  setof(CN, takesOption(SN, CN), OptCourses).


remove_SID([], []).
remove_SID([(SID, SN)|T1], [SN|T2]):-
  remove_SID(T1, T2).

studentsInHouse(House, Students):-
  setof((SID, SN), SID^SN^student(SID, SN, House), Students1),
  remove_SID(Students1, Students).

studentsOnCourse(SCN, CN, StudentsByHouse):-
  (compCourse(SCN, CN, _); optCourse(SCN,CN, _)),
  enrolled(SID, SCN),
  findall(House-Students, studentsInHouse(House,Students), StudentsByHouse).

% Question 10
sharedCourse(SN1, SN2, CN):-
  enrolled(SID1, SCN),
  student(SID1, SN1, _),
  enrolled(SID2, SCN),
  student(SID2, SN2, _),
  (compCourse(SCN, CN, _) ; optCourse(SCN, CN, _)),
  SN1 \= SN2.

sameOptions(SN1, SN2, Courses):-
  takesAllOptions(SN1, Courses1),
  takesAllOptions(SN2, Courses2),
  SN1 \= SN2,
  setof(C, (member(C, Courses1), member(C, Courses2)), Courses),
  length(Courses, 3).
