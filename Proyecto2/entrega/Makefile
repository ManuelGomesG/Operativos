#
# Taller de Sistemas Operativos I.
# Abril-Julio 2015.
# Proyecto 2.
#
# Makefile para compilar.
#
# Hecho por:
# 	Ricardo Münch. Carnet: 11-10684.
# 	Manuel Gomes. Carnet: 11-10375.
#

CFLAGS = -g -Wall
CC = gcc
OBJS = funciones.o main.o

MiCuento: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: ./main.c
		$(CC) $(CFLAGS) -c ./main.c

funciones.o: ./funciones.c ./funciones.h
		$(CC) $(CFLAGS) -c $<

clean:
	rm $(OBJS) MiCuento