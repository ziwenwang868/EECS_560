lab5: main.o exe.o q_hash.o data.o d_hash.o time.o
	g++ -std=c++11 -g -Wall main.o q_hash.o exe.o time.o d_hash.o data.o -o lab5
main.o: main.cpp exe.h 
	g++ -std=c++11 -g -Wall -c main.cpp
exe.o: exe.h exe.cpp q_hash.h d_hash.h time.h
	g++ -std=c++11 -g -Wall -c exe.cpp
q_hash.o: q_hash.o q_hash.cpp data.h
	g++ -std=c++11 -g -Wall -c q_hash.cpp
d_hash.o: d_hash.o d_hash.cpp data.h
	g++ -std=c++11 -g -Wall -c d_hash.cpp
data.o: data.h data.cpp
	g++ -std=c++11 -g -Wall -c data.cpp
time.o: time.h time.cpp
	g++ -std=c++11 -g -Wall -c time.cpp
clean:
	rm *.o lab5


