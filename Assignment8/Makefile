CXXFLAGS := -std=c++17 -Wall -Iinclude -MMD -MP

SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin

TARGET := $(BIN_DIR)/employeemanagement

# Find all .cpp files recursively
SOURCES := $(shell find $(SRC_DIR) -name "*.cpp")

# Convert src/xxx.cpp → build/xxx.o
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: $(TARGET)

# Create directories if missing
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Linking
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile each source file to corresponding object
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

-include $(OBJECTS:.o=.d)
