COMPILE = gcc
FLAGS = -W -Wall -pedantic -ansi
DEPS = question1.o question2.o question3.o question4.o

all: $(DEPS)
	$(COMPILE) $(FLAGS) -o main.exe main.c $(DEPS) -lm

question1.o: question1.c
	$(COMPILE) $(FLAGS) -c question1.c

question2.o: question2.c
	$(COMPILE) $(FLAGS) -c question2.c

question3.o: question3.c
	$(COMPILE) $(FLAGS) -c question3.c

question4.o: question4.c
	$(COMPILE) $(FLAGS) -c question4.c

clean:
	rm *.o *.exe *.out
