# all: sim

# sim: Sim.o Event.o EmptyDataCollectionException.o
# 	g++ -std=c++98 -pedantic -Wall -o sim Sim.o Event.o EmptyDataCollectionException.o

# Sim.o: Sim.cpp Event.h Queue.h PriorityQueue.h
# 	g++ -std=c++98 -pedantic -Wall -c Sim.cpp

# EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
# 	g++ -std=c++98 -pedantic -Wall -c EmptyDataCollectionException.cpp

# Event.o: Event.h Event.cpp
# 	g++ -std=c++98 -pedantic -Wall -c Event.cpp

# Node.o: Node.h Node.cpp
# 	g++ -std=c++98 -pedantic -Wall -c Node.cpp

# clean:
# 	rm -f sim *.o


all: simulation

simulation: Sim.o Queue.h PriorityQueue.h Node.h Event.o EmptyDataCollectionException.o
	g++ -Wall -std=c++11 -o simulation Sim.o Event.o EmptyDataCollectionException.o

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f simulation *.o