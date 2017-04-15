CXX = g++
CFLAGS = -Ofast -march=native -std=c++14
INCLUDE = ./include
SRC = ./src
DST = ./dst
BIN = ./bin
UTIL = ./src/util
OBJS = $(DST)/main.o $(DST)/vfs.o $(DST)/cmdline_wiz.o

all: $(OBJS) Makefile
	mkdir -p dst
	mkdir -p bin
	$(CXX) -o $(BIN)/chufs  $(OBJS) $(LDFLAGS)

clean:
	rm -f ./dst/*
	rm -f ./bin/*

$(DST)/%.o: $(SRC)/%.cc
	mkdir -p dst
	$(CXX) $(CFLAGS) -g -c -o $(DST)/$*.o $(SRC)/$*.cc $(LDFLAGS)

$(DST)/%.o: $(UTIL)/%.cc
	mkdir -p dst
	$(CXX) $(CFLAGS) -g -c -o $(DST)/$*.o $(UTIL)/$*.cc $(LDFLAGS)
