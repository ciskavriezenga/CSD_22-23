CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++2a
LDFLAGS= -ljack
SOURCE= melody.o square.o main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
