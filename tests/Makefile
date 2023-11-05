CXX = g++
CXXFLAGS = -std=c++11 -I../include
SRC_DIR = ../src
OBJ_DIR = ../obj
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Specify the main program source file
MAIN_SOURCE = TestTensor.cpp

TARGET = TestTensor.out

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAIN_SOURCE) $^ -o $@ -lcppunit

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(TARGET)
