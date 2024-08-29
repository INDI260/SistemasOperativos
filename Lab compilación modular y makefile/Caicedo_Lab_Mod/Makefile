GCC = gcc
FLAGS = -c

PROGRAMAS: labPrincipal

labPrincipal:
	$(GCC) $(FLAGS) librerialab.c
	$(GCC) $@.c librerialab.o -o $@
	$(RM) *.o
	
clear:
	$(RM) *.o labPrincipal