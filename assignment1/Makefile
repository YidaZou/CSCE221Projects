CXX=g++
IDIR=$(PWD)/include
CXXFLAGS=-O3 -std=c++11 -Wall -Werror -g -I$(IDIR)


all: ./obj/w1.out ./obj/w2.out ./obj/w3.out ./obj/w4.out ./obj/nodeinfo.out ./obj/printlist.out

./obj/w1.out: ./obj/w1.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/w1.o: ./src/w1.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

./obj/w2.out: ./obj/w2.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/w2.o: ./src/w2.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

./obj/w3.out: ./obj/w3.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/w3.o: ./src/w3.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

./obj/w4.out: ./obj/w4.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/w4.o: ./src/w4.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

./obj/nodeinfo.out: ./obj/nodeinfo.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/nodeinfo.o: ./src/NodeInfo.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

./obj/printlist.out: ./obj/printlist.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/printlist.o: ./src/PrintList.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


.PHONY: clean
clean:
	rm -rf $(ODIR)/*
