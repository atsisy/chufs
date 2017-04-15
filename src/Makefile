

all: $(DST)


$(DST)/%.o: $(SRC)/%.cc
	mkdir -p dst
	$(CXX) $(CFLAGS) -Ofast -march=native -std=c++14 -c -o $(DST)/$*.o $(SRC)/$*.cpp $(LDFLAGS)
