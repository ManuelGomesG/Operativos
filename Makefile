# Makefile para aplicacion "main"
CFLAGS	= -ggdb
CC	= gcc
OBJS	= funciones.o main.o 

./ejecutables/main:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@


main.o:	./codigo/main.c ./codigo/funciones.h
		$(CC) $(CFLAGS) -c ./codigo/main.c

funciones.o: ./codigo/funciones.c
		$(CC) $(CFLAGS) -c $<

clean:
		/bin/rm *.o