# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker.
CXX = g++
CC = $(CXX)

# Generate dependencies in the d file
DEPFLAGS = -MT $@ -MMD -MP -MF $.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU’s libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O0 -Wall
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g

# Targets
PROGS = userprog
all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
userprog: userprog.o User.o UserTable.o

# Include the.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)