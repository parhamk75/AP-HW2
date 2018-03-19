CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14
OBJECTS = Qmain.o queue.o
TARGET = Qmain


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
Qmain.o: Qmain.cpp queue.h
	$(CXX) $(CXXFLAGS) Qmain.cpp
queue.o: queue.cpp
	$(CXX) $(CXXFLAGS) queue.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)

