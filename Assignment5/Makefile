# Makefile for Assignment 5

# Compiler and flags
CXXFLAGS = -std=c++17 -Wall -Iinclude -MMD -MP

# Directories
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

# Executables
PROGRAMS = LiteralsAddition NumericSorter WordFrequency
TARGETS = $(addprefix $(BIN_DIR)/,$(PROGRAMS))

# Default target: build all executables
all: $(TARGETS)

# Ensure build and bin directories exist
$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

# Pattern rule for building executables
$(BIN_DIR)/%: $(OBJ_DIR)/%.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Pattern rule for compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run targets
run-%: $(BIN_DIR)/%
	./$<

$(PROGRAMS): %: $(BIN_DIR)/%

.PRECIOUS: $(OBJ_DIR)/%.o

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
