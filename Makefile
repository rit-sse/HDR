CXX ?= g++

CXXFLAGS += -c -Wall $(shell pkg-config --cflags opencv) -std=c++11
LDFLAGS += $(shell pkg-config --libs --static opencv)

all: hdr

hdr: main.o; $(CXX) $< -o $@ $(LDFLAGS)

%.o: %.cpp; $(CXX) $< -o $@ $(CXXFLAGS)

clean: ; rm -f main.o hdr
