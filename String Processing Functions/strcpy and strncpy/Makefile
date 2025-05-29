CXX=g++
CXXFLAGS=-std=c++23
#set exec names to the base name of the directory, and
#replace all spaces with underscores
EXEC:=$(shell basename "`pwd`" | sed 's/ /_/g')
SRCS:=$(shell find *.cpp)
OBJS:= $(SRCS:%.cpp=%.o)

all: $(EXEC)

full: clean all

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< 
	
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 
	
clean:
	rm *.o $(EXEC) -f
