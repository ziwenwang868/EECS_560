hash2: main.o exe.o hash.o data.o
	g++ -std=c++11 -g -Wall main.o hash.o exe.o data.o -o hash2
main.o: main.cpp exe.h 
	g++ -std=c++11 -g -Wall -c main.cpp
exe.o: exe.h exe.cpp hash.h
	g++ -std=c++11 -g -Wall -c exe.cpp
hash.o: hash.o hash.cpp data.h
	g++ -std=c++11 -g -Wall -c hash.cpp
data.o: data.h data.cpp
	g++ -std=c++11 -g -Wall -c data.cpp
clean:
	rm *.o hash2


