CXX = g++
CXXFLAGS = -std=c++14 -Wall 
SRC_DIR = ../src
OBJ_DIR = ../obj
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))


MAIN_SOURCE = BenchmarkTensors.cpp
TARGET = BenchmarkTensors.out

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAIN_SOURCE) $^  -o $@ -O3

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $ -O3

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(TARGET)