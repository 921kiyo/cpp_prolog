main: main.o Contestant.o Team.o University.o
	g++ -Wall -g main.o Contestant.o Team.o University.o -o main

main.o: main.cpp Contestant.cpp Contestant.h Team.cpp Team.h University.cpp University.h
	g++ main.cpp Contestant.cpp Team.cpp University.cpp -c

Contestant.o: Contestant.cpp Contestant.h
	g++ Contestant.cpp -c

Team.o: Team.cpp Team.h
	g++ Team.cpp -c

University.o: University.cpp University.h
	g++ University.cpp -c

# main:  main.cpp Contestant.cpp Contestant.h Team.cpp Team.h University.cpp University.h
# 	g++ -Wall -g main.cpp Contestant.cpp Team.cpp University.cpp -o main
