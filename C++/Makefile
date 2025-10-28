# =====================================================
#  Makefile — compile & run any .cpp file with:
#      make filename.cpp
# =====================================================

# Disable built-in implicit rules so Make doesn’t get confused
.SUFFIXES:

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# Directories
BIN_DIR := bin

# Default goal
.DEFAULT_GOAL := help

# Always-run sentinel
.PHONY: FORCE help clean_all
FORCE:

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Main rule: allows "make file.cpp"
%.cpp: FORCE | $(BIN_DIR)
	@src="$@"; \
	name=$${src%.cpp}; \
	echo " 🔧 Compiling $$src..."; \
	$(CXX) $(CXXFLAGS) $$src -o $(BIN_DIR)/$$name; \
	echo "✅ Build complete. Running program..."; \
	echo "---------------------------------------"; \
	./$(BIN_DIR)/$$name; \
	echo "---------------------------------------"; \
	echo "🏁 Program finished."; \
	echo ""

# Clean commands
clean_%:
	@echo "Removing executable $*..."
	rm -f $(BIN_DIR)/$*

clean_all:
	@echo "Removing all executables..."
	rm -f $(BIN_DIR)/*

# Help text
help:
	@echo "Usage:"
	@echo "  make <file>.cpp     -> compile & run <file>.cpp (always rebuilds)"
	@echo "  make clean_<file>   -> remove bin/<file>"
	@echo "  make clean_all      -> remove all bin/*"
