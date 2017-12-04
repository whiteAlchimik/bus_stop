main : main.o
	g++ -std=c++11 -o main main.o time.o service.o timetable.o timetablemanagement.o
main.o : main.cpp timetablemanagement.o
	g++ -std=c++11 -c -o main.o main.cpp
time.o: time.h time.cpp
	g++ -std=c++11 -c -o time.o time.cpp
service.o : service.h service.cpp time.o
	g++ -std=c++11 -c -o service.o service.cpp
timetable.o : timetable.h timetable.cpp service.o
	g++ -std=c++11 -c -o timetable.o timetable.cpp
timetablemanagement.o : timetablemanagement.h timetablemanagement.cpp timetable.o
	g++ -std=c++11 -c -o timetablemanagement.o timetablemanagement.cpp
run:
	./main
clear:
	rm *.o main output
