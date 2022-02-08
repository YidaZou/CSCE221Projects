CXX=g++
IDIR=$(PWD)/include
ODIR=$(PWD)/obj
SDIR=$(PWD)/src
DEPS=$(IDIR)/NodeInfo.h
SRC=$(SDIR)/NodeInfo.cpp
OBJ=$(ODIR)/nodeinfo.o
CXXFLAGS=-O3 -Wall -Werror -g -I$(IDIR)

$(ODIR)/nodeinfo: $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/nodeinfo.o: $(SRC) $(DEPS)
    $(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
    rm -rf $(ODIR)/*