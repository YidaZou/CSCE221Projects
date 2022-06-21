CXX=g++
IDIR=$(PWD)/include
ODIR=$(PWD)/obj
SDIR=$(PWD)/src
#DEPS=$(IDIR)/NodeInfo.h
SRC=$(SDIR)/hashing.cpp
MSRC=$(SDIR)/rbtree.cpp
#//PSRC=$(SDIR)/PrintList.cpp
OBJ=$(ODIR)/hashing.o
MOBJ=$(ODIR)/rbtree.o
#POBJ=$(ODIR)/printlist.o
CXXFLAGS=-O3 -std=c++11 -Wall -Werror -g -I$(IDIR)

.PHONY: all
all: $(ODIR)/hashing $(ODIR)/rbtree

$(ODIR)/hashing: $(OBJ) $(POBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
$(OBJ): $(SRC) $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
$(POBJ): $(PSRC) $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/rbtree: $(MOBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
$(MOBJ): $(MSRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(ODIR)/*
