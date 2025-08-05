# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -mwindows
LIBS = -static -lraylib -lwinmm -lgdi32 -lopengl32 -lm

# Directories
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
ASSETS_DIR = assets

# Files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/Hangman.exe

# Default target
all: $(TARGET) copy-assets

# Create folders if needed
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Link object files into final binary
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LIBS)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Copy assets to bin folder
copy-assets: $(BIN_DIR)
	cp -r $(ASSETS_DIR) $(BIN_DIR)/

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run game
run: all
	./$(TARGET)

.PHONY: all clean run copy-assets
