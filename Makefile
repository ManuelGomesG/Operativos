CFLAGS = -ggdb
CC = gcc
OBJS = funciones.o lista.o main.o

./ejecutables/friendfind: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: ./codigo/main.c
		$(CC) $(CFLAGS) -c ./codigo/main.c

funciones.o: ./codigo/funciones.c
		$(CC) $(CFLAGS) -c $<

lista.o: ./codigo/lista.c ./codigo/header_p1.h
		$(CC) $(CFLAGS) -c $<

clean:
		/bin/rm *.o