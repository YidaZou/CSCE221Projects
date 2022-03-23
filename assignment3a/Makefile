CXX=g++
IDIR=$(PWD)/include
ODIR=$(PWD)/obj
SDIR=$(PWD)/src
DEPS=$(IDIR)/NodeInfo.h
SRC=$(SDIR)/NodeInfo.cpp
MSRC=$(SDIR)/MergeVector.cpp
#//PSRC=$(SDIR)/PrintList.cpp
OBJ=$(ODIR)/nodeinfo.o
MOBJ=$(ODIR)/mergevector.o
#POBJ=$(ODIR)/printlist.o
CXXFLAGS=-O3 -std=c++11 -Wall -Werror -g -I$(IDIR)

.PHONY: all
all: $(ODIR)/nodeinfo $(ODIR)/mergevector

$(ODIR)/nodeinfo: $(OBJ) $(POBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
$(OBJ): $(SRC) $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
$(POBJ): $(PSRC) $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/mergevector: $(MOBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
$(MOBJ): $(MSRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(ODIR)/*
