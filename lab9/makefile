lab9: main.o exe.o minleftist.o node.o minskew.o
	g++ -g -std=c++11 -Wall main.o exe.o minleftist.o node.o minskew.o -o lab9

main.o: main.cpp exe.h
	g++ -g -std=c++11 -Wall -c main.cpp

exe.o: exe.h minleftist.h minskew.h
	g++ -g -std=c++11 -Wall -c exe.cpp

minleftist.o: minleftist.h minleftist.cpp node.h
	g++ -g -std=c++11 -Wall -c minleftist.cpp
minskew.o: minskew.h minskew.cpp node.h
	g++ -g -std=c++11 -Wall -c minskew.cpp

node.o: node.h node.cpp
	g++ -g -std=c++11 -Wall -c node.cpp
clean:
	rm *.o lab9
