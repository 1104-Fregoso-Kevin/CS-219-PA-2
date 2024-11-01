PA2: main.o Read.o Operations.o Flags.o
	g++ -o PA2 main.o Read.o Operations.o Flags.o

main.o: main.cpp
	g++ -c main.cpp

Read.o: Read.cpp Read.h
	g++ -c Read.cpp

Operations.o: Operations.cpp Operations.h
	g++ -c Operations.cpp

Flags.o: Flags.cpp Flags.h
	g++ -c Flags.cpp

clean:
	rm *.o PA2
