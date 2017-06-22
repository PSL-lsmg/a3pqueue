all: sim

sim: Sim.o Event.o Queue.o
	g++ -std=c++98 -pedantic -Wall -o sim Sim.o Event.o Queue.o

Sim.o: Sim.cpp Event.h
	g++ -std=c++98 -pedantic -Wall -c Sim.cpp

Queue.o: Queue.h Queue.cpp
	g++ -std=c++98 -pedantic -Wall -c Queue.cpp

Event.o: Event.h Event.cpp
	g++ -std=c++98 -pedantic -Wall -c Event.cpp

clean:
	rm -f sim *.o