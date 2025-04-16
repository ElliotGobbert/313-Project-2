# Compiler definitions
CC = gcc
CXX = g++
CFLAGS = -Wall -std=c11
CXXFLAGS = -Wall -std=c++17

# Executable names
C_EXE = matrix_c
CPP_EXE = matrix_cpp

# Source files
C_SRC = matrix.c      # includes main() in C
CPP_SRC = matrix.cpp  # includes main() in C++

# Targets

# Build C version
$(C_EXE): $(C_SRC)
	$(CC) $(CFLAGS) -o $(C_EXE) $(C_SRC)

# Build C++ version
$(CPP_EXE): $(CPP_SRC)
	$(CXX) $(CXXFLAGS) -o $(CPP_EXE) $(CPP_SRC)

# Run C version
run-c: $(C_EXE)
	./$(C_EXE)

# Run C++ version
run-cpp: $(CPP_EXE)
	./$(CPP_EXE)

# Clean everything
clean:
	rm -f $(C_EXE) $(CPP_EXE)