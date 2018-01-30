CC = g++
IDIR = ./include
CFLAGS = -c -Wall -std=c++11 -I $(IDIR)
OBJDIR = ./obj/

objects = $(addprefix $(OBJDIR), main.o)

Debug: all
all: protcat

protcat: $(objects)
	mkdir -p bin/Debug
	$(CC) -Wall -o bin/Debug/protcat $(objects)
	mkdir -p ~/bin
	cp bin/Debug/protcat ~/bin/protcat

$(OBJDIR)main.o: main.cpp
	mkdir -p obj
	$(CC) $(CFLAGS) main.cpp -o $@

clean:
	rm -rf $(OBJDIR)*.o bin/Debug/protcat	~/bin/protcat




