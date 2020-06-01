COMPILE = gcc
FLAGS = -W -Wall -Werror -pedantic -ansi
PROGS = exercise-3.c exercise-4.c fathm_ft.c first.c nogood.c two_func.c

all: $(PROGS)
	make first.out
	make fathm_ft.out
	make two_func.out
	make nogood.out
	make exercise-3.out
	make exercise-4.out


first.out: first.c
	$(COMPILE) $(FLAGS) -o first.out first.c

fathm_ft.out: fathm_ft.c
	$(COMPILE) $(FLAGS) -o fathm_ft.out fathm_ft.c

two_func.out: two_func.c
	$(COMPILE) $(FLAGS) -o two_func.out nogood.c

nogood.out: nogood.c
	$(COMPILE) $(FLAGS) -o nogood.out nogood.c

exercise-3.out: exercise-3.c
	$(COMPILE) $(FLAGS) -o exercise-3.out exercise-3.c

exercise-4.out: exercise-4.c
	$(COMPILE) $(FLAGS) -o exercise-4.out exercise-4.c

clean:
	rm *.out
