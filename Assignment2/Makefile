# Makefile for Assignment 2

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -MMD -MP

# Directories
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

# Executables
PROGRAMS = numberswap studentmanager
TARGETS = $(addprefix $(BIN_DIR)/,$(PROGRAMS))

# Ensure build and bin directories exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Source files for each program
NUMBERSWAP_SRCS = NumberSwap.cpp
STUDENT_SRCS = Student.cpp UiUtility.cpp Validation.cpp Main.cpp StudentManager.cpp

# Object files
NUMBERSWAP_OBJS = $(addprefix $(OBJ_DIR)/,$(NUMBERSWAP_SRCS:.cpp=.o))
STUDENT_OBJS    = $(addprefix $(OBJ_DIR)/,$(STUDENT_SRCS:.cpp=.o))

# Default target: build all executables
all: $(TARGETS)

# Build rules for executables
$(BIN_DIR)/numberswap: $(NUMBERSWAP_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN_DIR)/studentmanager: $(STUDENT_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Generic object build rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run targets
run-%: $(BIN_DIR)/%
	$<

# Clean rule
clean:
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(BIN_DIR)/*

# Include dependency files
-include $(OBJ_DIR)/*.d