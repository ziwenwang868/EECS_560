tree: main.o exe.o data.o btree.o
	g++ -std=c++11 -g -Wall main.o data.o exe.o btree.o -o tree
main.o: main.cpp exe.h
	g++ -std=c++11 -g -Wall -c main.cpp
exe.o: exe.h exe.cpp btree.h
	g++ -std=c++11 -g -Wall -c exe.cpp
btree.o: btree.h btree.cpp data.h
	g++ -std=c++11 -g -Wall -c btree.cpp
data.o: data.h data.cpp
	g++ -std=c++11 -g -Wall -c data.cpp
clean:
	rm *.o tree
