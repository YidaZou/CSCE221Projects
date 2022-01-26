hello: factorial.cpp hello.cpp main.cpp
	g++ $^ -o $@

CXX = "g++"
CXXFLAGS = "-Wall -Werror -Wextra"
OBJECTS = factorial.o hello.o main.o

main.o: main.cpp
	g++ -c main.cpp

factorial.o: factorial.cpp
	g++ -c factorial.cpp

hello.o: hello.cpp
	g++ -c hello.cpp

squareroot.o: squareroot.cpp
	g++ -c squareroot.cpp -include cmath
