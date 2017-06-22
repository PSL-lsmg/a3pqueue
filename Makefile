all: sim

sim: Sim.o Event.o EmptyDataCollectionException.o
	g++ -std=c++98 -pedantic -Wall -o sim Sim.o Event.o EmptyDataCollectionException.o

Sim.o: Sim.cpp Event.h Queue.h PriorityQueue.h
	g++ -std=c++98 -pedantic -Wall -c Sim.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -std=c++98 -pedantic -Wall -c EmptyDataCollectionException.cpp

Event.o: Event.h Event.cpp
	g++ -std=c++98 -pedantic -Wall -c Event.cpp

clean:
	rm -f sim *.o