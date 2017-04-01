
all: wrastlin


wrastlin: main.o wrestler.o weight.o team.o meet.o records.o tournament.o tourneyWeight.o
	g++ -o bin/wrastlin obj/main.o obj/wrestler.o obj/weight.o obj/team.o obj/meet.o obj/records.o obj/tournament.o obj/tourneyWeight.o

main.o: src/main.cpp
	g++ -c -g  -std=c++11 -o obj/main.o src/main.cpp

wrestler.o: src/wrestler.cpp
	g++ -c -g  -std=c++11 -o obj/wrestler.o src/wrestler.cpp

weight.o: src/weight.cpp
	g++ -c -g -std=c++11 -o obj/weight.o src/weight.cpp

team.o: src/team.cpp
	g++ -c -g -std=c++11 -o obj/team.o src/team.cpp

meet.o: src/meet.cpp
	g++ -c -g -std=c++11 -o obj/meet.o src/meet.cpp

records.o: src/records.cpp
	g++ -c -g -std=c++11 -o obj/records.o src/records.cpp

tournament.o: src/tournament.cpp
	g++ -c -g -std=c++11 -o obj/tournament.o src/tournament.cpp

tourneyWeight.o: src/tourneyWeight.cpp
	g++ -c -g -std=c++11 -o obj/tourneyWeight.o src/tourneyWeight.cpp

clean: 
	rm obj/*.o  bin/wrastlin

install:
	cp bin/wrastlin /usr/local/bin/
