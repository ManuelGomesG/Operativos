CFLAGS = -g -Wall
CC = gcc
OBJS = funciones.o lista_t.o lista.o main.o

friendfind: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: ./codigo/main.c
		$(CC) $(CFLAGS) -c ./codigo/main.c

funciones.o: ./codigo/funciones.c
		$(CC) $(CFLAGS) -c $<

lista_t.o: ./codigo/lista_t.c
		$(CC) $(CFLAGS) -c $<

lista.o: ./codigo/lista.c ./codigo/header_p1.h
		$(CC) $(CFLAGS) -c $<

clean:
		/bin/rm *.o
		rm friendfind
