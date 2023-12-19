CXX = g++
CC = $(CXX)
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d
CPPFLAGS = -std=c++11 -I.
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g

# Source files
SRCS = date_test.cc date.cc test_toString.cc main.cc TagRemover.cc findPrime.cc test_tagremover.cc tagmain.cc findPrime.cc prime_test.cc string_cast_test.cc
# main.cc TagRemover.cc findPrime.cc
# Object file names from source file names
OBJS = $(SRCS:.cc=.o)

# Targets
PROGS = main

all: $(PROGS)
	clear

# Link executable
main: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^


clean:
	rm -f $(PROGS) $(OBJS) *.d
	clear

test_date: date_test.o date.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_toString: test_toString.o date.o
	$(CXX) $(LDFLAGS) -o $@ $^


findPrime: main.cc TagRemover.cc findPrime.cc
	$(CXX) $(LDFLAGS) -o $@ $^

#tests
test_tagremover: test_tagremover.o TagRemover.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_prime: prime_test.o findPrime.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_string_cast: string_cast_test.o date.o
	$(CXX) $(LDFLAGS) -o $@ $^

# Build object files
%.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
