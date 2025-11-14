# Makefile for Assignment 2
 
# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
 
# Directories
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin
 
# Executables
NUMBERSWAP = $(BIN_DIR)/numberswap
STUDENTMANAGER  = $(BIN_DIR)/studentmanager
 
# Ensure build and bin directories exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))
 
# Source files
STUDENT_SRCS = $(SRC_DIR)/Student.cpp $(SRC_DIR)/UiUtility.cpp $(SRC_DIR)/Validation.cpp $(SRC_DIR)/Main.cpp $(SRC_DIR)/StudentManager.cpp
STUDENT_OBJS = $(OBJ_DIR)/Student.o $(OBJ_DIR)/UiUtility.o $(OBJ_DIR)/Validation.o $(OBJ_DIR)/Main.o $(OBJ_DIR)/StudentManager.o
 
# Default target: build both executables
all: $(NUMBERSWAP) $(STUDENTMANAGER)

# NumberSwap target: builds only number swap execute file 
numberswap: $(NUMBERSWAP)

# StudentManager target: builds only student manager execte file
studentmanager: $(STUDENTMANAGER)

# Build numberswap

$(NUMBERSWAP): $(OBJ_DIR)/numberswap.o
	$(CXX) $(CXXFLAGS) $< -o $@
 
$(OBJ_DIR)/numberswap.o: $(SRC_DIR)/numberswap.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
# Build studentdatamanager

$(STUDENTMANAGER): $(STUDENT_OBJS)
	$(CXX) $(CXXFLAGS) $(STUDENT_OBJS) -o $@
 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
# Run the number swap program

run-numberswap: numberswap
	./bin/numberswap

# Run the student manager

run-studentmanager: studentmanager
	./bin/studentmanager

# Clean rule

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*