CC = gcc                       
CFLAGS = -g -Wall
#OBJS = main.o file1.o 
PROG = MiCuento
SOURCE = main.c hijos.c randn.c  # define a macro SOURCE with a list of source files
OBJECTS = $(SOURCE:.c=.o) 

$(PROG):
		$(CC) $(LDFLAGS) $(OBJS) -o $(PROG) $(SOURCE) # here we use CC macro, by writing $(CC) 

main.o: main.c file1.h
		$(CC) $(CFLAGS) -c main.c

file1.o: file1.c file1.h
		$(CC) $(CFLAGS) -c file1.c

clean:
		$(RM) $(PROG) $(OBJS)

