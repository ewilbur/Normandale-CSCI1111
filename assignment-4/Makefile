COMPILE = gcc
FLAGS = -W -Wall -pedantic -ansi
PROGS = change.c int_operators.c

all: $(PROGS)
	make change.out
	make int_operators.out

change.out: change.c
	$(COMPILE) $(FLAGS) -o change.out change.c -lm

int_operators.out : int_operators.c
	$(COMPILE) $(FLAGS) -o int_operators.out int_operators.c

clean:
	rm -f *.out
