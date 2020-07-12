heap: main.o exe.o data.o patient_max.o doctor_min.o
	g++ -std=c++11 -g -Wall main.o exe.o data.o patient_max.o doctor_min.o -o heap
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
exe.o: exe.cpp exe.h data.h patient_max.h doctor_min.h
	g++ -std=c++11 -g -Wall -c exe.cpp
data.o: data.h data.cpp
	g++ -std=c++11 -g -Wall -c data.cpp
patient_max.o: patient_max.h patient_max.cpp data.h
	g++ -std=c++11 -g -Wall -c patient_max.cpp
doctor_min.o: doctor_min.h doctor_min.cpp data.h
	g++ -std=c++11 -g -Wall -c doctor_min.cpp
clean:
	rm *.o heap
