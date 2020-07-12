lab10a: main.o exe.o disjoint.o set_node.o
	g++ -g -std=c++11 -Wall main.o exe.o disjoint.o set_node.o -o lab10a

main.o: main.cpp exe.h
	g++ -g -std=c++11 -Wall -c main.cpp

exe.o: exe.h disjoint.h
	g++ -g -std=c++11 -Wall -c exe.cpp

disjoint.o: disjoint.h disjoint.cpp set_node.h
	g++ -g -std=c++11 -Wall -c disjoint.cpp

set_node.o: set_node.h set_node.cpp
	g++ -g -std=c++11 -Wall -c set_node.cpp
clean:
	rm *.o lab10a
