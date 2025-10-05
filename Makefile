# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# Directories
SRC_DIR := .
BIN_DIR := bin

# Default target (if you just type "make")
.DEFAULT_GOAL := help

# Create bin directory if not exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)


# Pattern rule: build any .cpp file into an executable of the same name
%: %.cpp | $(BIN_DIR)
	@echo " 🔧 Compiling $<..."
	@$(CXX) $(CXXFLAGS) $< -o $(BIN_DIR)/$@
	@echo "✅ Build complete. Running program..."
	@echo "---------------------------------------"
	@./$(BIN_DIR)/$@
	@echo "---------------------------------------"
	@echo "🏁 Program finished."
	@echo " "

# Clean a specific target: make clean stack
clean:
ifeq ($(filter clean,$(MAKECMDGOALS)),clean)
	@echo "Usage:"
	@echo "  make clean target   -> removes a specific executable"
	@echo "  make clean all      -> removes all executables"
endif

# Clean a specific program
clean_%:
	@echo "Removing executable $*..."
	rm -f $ $*

# Clean all executables in the directory
clean_all:
	@echo "Removing all executables..."
	rm -f $(basename $(wildcard *.cpp))

# Helpful output
help: 
	@echo "Usage:"
	@echo "  make <name>		  -> compile <name>.cpp to <name>"
	@echo "  make clean_<name>.   -> remove <name> executable"
	@echo " make clean_all		  -> remove all executables"