CC=g++
OBJDIR=./obj
SRCDIR=.
OBJS=$(addprefix $(OBJDIR)/,main.o Implementation.o functions.o quickSort.o)  #add all object files here
LIBS= Interface.hpp quickSort.hpp
FLAGS=-I -g3 -Wall -std=c++11

executable : $(OBJS)
	$(CC) -o executable $(OBJS) $(FLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(FLAGS)

clean:
	rm -f obj/*.o executable
