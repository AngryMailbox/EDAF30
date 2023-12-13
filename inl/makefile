# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker.
CXX = g++
CC = $(CXX)

# Generate dependencies in the d file
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU’s libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -Wall -Wextra -Werror -pedantic-errors
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g

# Targets
PROGS = test_concatenation test_join_iterator test_no_copy
all: $(PROGS)

# Targets rely on implicit rules for compiling and linking

# test_concat: test_concat.o
# test_join_iterator: test_join_iterator.o

# Include the.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

testall: main.o test_concatenation.o test_join_iterator.o test_no_copy.o
	rm -f *.o *.d
	rm -f d
	clear
	./main
	@echo "Done"

test1: test_concatenation
	rm -f *.o *.d
	rm -f d
	clear
	./test_concatenation
	@echo "Done"

test2: test_join_iterator
	rm -f *.o *.d
	rm -f d
	clear
	./test_join_iterator
	@echo "Done"

test3: test_no_copy
	rm -f *.o *.d
	rm -f d
	./test_no_copy
	@echo "Done"