CC = gcc                       
CFLAGS = -g -Wall
#OBJS = main.o file1.o 
PROG = MiCuento
SOURCE = main.c Hijos.c randn.c  
OBJECTS = $(SOURCE:.c=.o) 

$(PROG):
		$(CC) $(LDFLAGS) $(OBJS) -o $(PROG) $(SOURCE) 


clean:
		rm $(PROG) $(OBJS)

