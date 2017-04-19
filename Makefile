CXX = g++
CC	= gcc
CXXFLAGS =  -std=c++14
OPTIMIZE = -Ofast -march=native
INCLUDE = ./include
SRC = ./src
DST = ./dst
BIN = ./bin
UTIL = ./src/util
OBJS = $(DST)/main.o $(DST)/vfs.o $(DST)/cmdline_wiz.o $(DST)/shell.o $(DST)/core_io.o $(DST)/wrapper_cxx.o

all: $(OBJS) Makefile
	mkdir -p dst
	mkdir -p bin
	$(CXX) -o $(BIN)/chufs  $(OBJS)

clean:
	rm -f ./dst/*
	rm -f ./bin/*

$(DST)/%.o: $(SRC)/%.cc
	mkdir -p dst
	$(CXX) $(CXXFLAGS) -g -c -o $(DST)/$*.o $(SRC)/$*.cc

$(DST)/%.o: $(UTIL)/%.cc
	mkdir -p dst
	$(CXX) $(CXXFLAGS) -g -c -o $(DST)/$*.o $(UTIL)/$*.cc

$(DST)/%.o: $(SRC)/%.c
	mkdir -p dst
	$(CC) $(OPTIMIZE) -g -c -o $(DST)/$*.o $(SRC)/$*.c
