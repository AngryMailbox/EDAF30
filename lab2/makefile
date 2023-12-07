# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC = $(CXX)

# Generate dependencies in .d files
DEPFLAGS = -MT $@ -MMD -MP -MF $.d
# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU’s libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O0 -Wall -Wextra -pedantic-errors
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++
# Targets
PROGS = spell test_edit_distance
all: $(PROGS)
# Targets rely on implicit rules for compiling and linking
spell: spell.o edit_distance.o dictionary.o word.o
test_edit_distance: test_edit_distance.o edit_distance.o
# Phony targets
.PHONY: all clean
# Standard clean
clean: rm -f .o $(PROGS)
# Include the.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)