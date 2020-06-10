COMPILE = gcc
FLAGS = -W -Wall -Werror -pedantic -ansi
PROGS = change.c my_int_operators.c

all: $(PROGS)
	make change.out
	make my_int_operators.out

change.out: change.c
	$(COMPILE) $(FLAGS) -o change.out change.c -lm

my_int_operators.out : my_int_operators.c
	$(COMPILE) $(FLAGS) -o my_int_operators.out my_int_operators.c

clean:
	rm *.out
