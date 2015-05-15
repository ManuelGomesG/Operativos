FLAGS = -g -Wall -o
OBJS = main.o lista.o
DEPS = lista.h

%.o: %.c $(DEPS)
	gcc -c $^

main: $(OBJS) $(DEPS)
	gcc $(FLAGS) $@ $^

.PHONY: clean

clean:
	rm $(OBJS) *.gch