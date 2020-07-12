heap: main.o exe.o data.o maxmin.o
	g++ -std=c++11 -g -Wall main.o exe.o data.o maxmin.o -o heap
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
exe.o: exe.cpp exe.h maxmin.h 
	g++ -std=c++11 -g -Wall -c exe.cpp
data.o: data.h data.cpp
	g++ -std=c++11 -g -Wall -c data.cpp
maxmin.o: maxmin.h maxmin.cpp data.h
	g++ -std=c++11 -g -Wall -c maxmin.cpp

clean:
	rm *.o heap
