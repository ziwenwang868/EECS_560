lab10b: main.o exe.o disjoint.o set_node.o graph.o
	g++ -g -std=c++11 -Wall main.o exe.o disjoint.o set_node.o graph.o -o lab10b

main.o: main.cpp exe.h
	g++ -g -std=c++11 -Wall -c main.cpp

exe.o: exe.h disjoint.h graph.h
	g++ -g -std=c++11 -Wall -c exe.cpp

disjoint.o: disjoint.h set_node.h disjoint.cpp
	g++ -g -std=c++11 -Wall -c disjoint.cpp
set_node.o: set_node.h set_node.cpp
	g++ -g -std=c++11 -Wall -c set_node.cpp
graph.o: graph.h graph.cpp disjoint.h
	g++ -g -std=c++11 -Wall -c graph.cpp
clean:
	rm *.o lab10b
