CXX = g++
CXXFLAGS = -std=c++14 
SRC_DIR = ../src
OBJ_DIR = ../obj
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
TESTHEADER = catch_amalgamated.cpp


MAIN_SOURCE = TestTensor.cpp
TARGET = TestTensor.out

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAIN_SOURCE) $^ $(TESTHEADER) -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(TARGET)