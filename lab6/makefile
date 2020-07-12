tree: main.o exe.o bst.o
	g++ -std=c++11 -g -Wall main.o exe.o bst.o -o tree
main.o: main.cpp exe.h
	g++ -std=c++11 -g -Wall -c main.cpp
exe.o: exe.h exe.cpp bst.h
	g++ -std=c++11 -g -Wall -c exe.cpp
bst.o: bst.h bst.cpp
	g++ -std=c++11 -g -Wall -c bst.cpp

clean:
	rm *.o tree
