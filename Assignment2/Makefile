# Makefile for Assignment 2

# Compiler and flags
CXXFLAGS := -std=c++17 -Wall -Iinclude -MMD -MP

# Directories
SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin

# Executables
PROGRAMS := numberswap studentmanager
TARGETS := $(addprefix $(BIN_DIR)/,$(PROGRAMS))

# Source files for each program
NUMBERSWAP_SRCS := NumberSwap.cpp
STUDENT_SRCS   := Student.cpp UiUtility.cpp Validation.cpp Main.cpp StudentManager.cpp

# Object files
NUMBERSWAP_OBJS := $(addprefix $(OBJ_DIR)/,$(NUMBERSWAP_SRCS:.cpp=.o))
STUDENT_OBJS    := $(addprefix $(OBJ_DIR)/,$(STUDENT_SRCS:.cpp=.o))

# Default target: build all executables
all: $(TARGETS)

# Ensure build and bin directories exist
$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

# Build rules for executables
$(BIN_DIR)/numberswap: $(NUMBERSWAP_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN_DIR)/studentmanager: $(STUDENT_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Generic object build rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run targets
run-%: $(BIN_DIR)/%
	$<

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Include dependency files
-include $(OBJ_DIR)/*.d
