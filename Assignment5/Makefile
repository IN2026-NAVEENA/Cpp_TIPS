# Makefile for Assignment 5

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O0

# Directories
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

# Executables
PROGRAMS = LiteralsAddition NumericSorter WordFrequency
TARGETS = $(addprefix $(BIN_DIR)/,$(PROGRAMS))

# Ensure build and bin directories exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default target: build all executables
all: $(TARGETS)

# Pattern rule for building executables
$(BIN_DIR)/%: $(OBJ_DIR)/%.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Pattern rule for compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run targets
run-%: $(BIN_DIR)/%
	./$<

.PRECIOUS: $(OBJ_DIR)/%.o

# Clean rule
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*
