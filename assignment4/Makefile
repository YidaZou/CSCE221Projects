CXX=g++
IDIR=$(PWD)/include
ODIR=$(PWD)/obj
SDIR=$(PWD)/src
#DEPS=$(IDIR)/heapsort.h
SRC=$(SDIR)/heapsort.cpp
MSRC=$(SDIR)/dijkstra.cpp
OBJ=$(ODIR)/heapsort.o
MOBJ=$(ODIR)/dijkstra.o
CXXFLAGS=-O3 -std=c++11 -Wall -Werror -g -I$(IDIR)

.PHONY: all
all: $(ODIR)/dijkstra

$(ODIR)/dijkstra: $(MOBJ) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
$(MOBJ): $(MSRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(ODIR)/*
