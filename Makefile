FLAGS = -g -Wall -o
OBJS = main.o lista.o
DEPS = lista.h

%.o: %.c $(DEPS)
	gcc -c $^

main: $(OBJS) $(DEPS)
<<<<<<< HEAD
	gcc $(FLAGS) $@ $^
=======
	gcc -o $@ $^
	chmod +x friendfind
>>>>>>> 530d49c7ac8cca0522786e4c150a1557c2d2676e

.PHONY: clean

clean:
	rm $(OBJS) *.gch