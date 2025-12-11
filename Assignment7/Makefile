# Compiler settings
CFLAGS = -Iinclude -Wall -O0
CXXFLAGS = -Iinclude -Wall -O0

# Directories
SRC = src
INC = include
BUILD = build
BIN = bin

# Targets
all: $(BIN)/factorial.exe $(BIN)/lambdafunction.exe $(BIN)/voidpointers.exe

# Ensure bin and build directories exist
$(BIN) $(BUILD):
	mkdir -p $(BIN) $(BUILD)

# factorial.exe depends on factorial.c and factorial.cpp
$(BIN)/factorial.exe: $(BUILD)/factorial_c.o $(BUILD)/factorial_cpp.o | $(BIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD)/factorial_c.o: $(SRC)/factorial.c $(INC)/factorial.h | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/factorial_cpp.o: $(SRC)/factorial.cpp $(INC)/factorial.h | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# lambdafunction.exe
$(BIN)/lambdafunction.exe: $(BUILD)/lambdafunction.o | $(BIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD)/lambdafunction.o: $(SRC)/lambdafunction.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# voidpointers.exe
$(BIN)/voidpointers.exe: $(BUILD)/voidpointers.o | $(BIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD)/voidpointers.o: $(SRC)/voidpointers.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run targets
run-factorial: $(BIN)/factorial.exe
	./$(BIN)/factorial.exe

run-lambdafunction: $(BIN)/lambdafunction.exe
	./$(BIN)/lambdafunction.exe

run-voidpointers: $(BIN)/voidpointers.exe
	./$(BIN)/voidpointers.exe

# Clean up build artifacts
clean:
	rm -rf $(BUILD) $(BIN)