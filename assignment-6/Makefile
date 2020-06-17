COMPILE = gcc
FLAGS = -W -Wall -pedantic -ansi
DEPS = part1.o part2.o part3.o part4.o

all: $(DEPS)
	$(COMPILE) $(FLAGS) -o main.exe main.c $(DEPS) -lm

part1.o: part1.c
	$(COMPILE) $(FLAGS) -c part1.c

part2.o: part2.c
	$(COMPILE) $(FLAGS) -c part2.c

part3.o: part3.c
	$(COMPILE) $(FLAGS) -c part3.c

part4.o: part4.c
	$(COMPILE) $(FLAGS) -c part4.c

clean:
	rm *.o *.exe *.out
