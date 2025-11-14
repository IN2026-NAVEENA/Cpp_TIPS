# Makefile for Assignment 1
 
# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall
 
# Directories
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin
 
# Executables
FUNCTIONCALLCOUNTER = $(BIN_DIR)/functioncallcounter
LEAPYEAR = $(BIN_DIR)/leapyear
NAMEMANIPULATOR = $(BIN_DIR)/namemanipulator
 
# Ensure build and bin directories exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))
 
# Default target: build all executables
all: $(FUNCTIONCALLCOUNTER) $(LEAPYEAR) $(NAMEMANIPULATOR)

# Function Call Counter target: builds only function call counter execute file 
functioncallcounter: $(FUNCTIONCALLCOUNTER)

# LeapYear target: builds only leap year execute file 
leapyear: $(LEAPYEAR)

# NameManipulator target: builds only name manipulator execute file 
namemanipulator: $(NAMEMANIPULATOR)

# Build functioncallcounter

$(FUNCTIONCALLCOUNTER): $(OBJ_DIR)/functioncallcounter.o
	$(CXX) $(CXXFLAGS) $< -o $@
 
$(OBJ_DIR)/functioncallcounter.o: $(SRC_DIR)/functioncallcounter.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build leapyear

$(LEAPYEAR): $(OBJ_DIR)/leapyear.o
	$(CXX) $(CXXFLAGS) $< -o $@
 
$(OBJ_DIR)/leapyear.o: $(SRC_DIR)/leapyear.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build namemanipulator

$(NAMEMANIPULATOR): $(OBJ_DIR)/namemanipulator.o
	$(CXX) $(CXXFLAGS) $< -o $@
 
$(OBJ_DIR)/namemanipulator.o: $(SRC_DIR)/namemanipulator.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
# Run the function call counter program

run-functioncallcounter: functioncallcounter
	./bin/functioncallcounter

# Run the leap year program

run-leapyear: leapyear
	./bin/leapyear

# Run the name manipulator program

run-namemanipulator: namemanipulator
	./bin/namemanipulator

# Clean rule

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*