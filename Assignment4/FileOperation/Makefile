# Compiler and flags
CXXFLAGS = -std=c++17 -Wall -Iinclude -MMD -MP

# Directories
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

# Executable
TARGET = $(BIN_DIR)/datalogger

# Source and object files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)

# Ensure build and bin directories exist
$(BIN_DIR):
	mkdir -p $@
$(OBJ_DIR):
	mkdir -p $@

# Link executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run target
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Include dependency files
-include $(OBJ_DIR)/*.d