OBJS = main.o lista.o persona.o
DEPS = lista.h persona.h

%.o: %.c $(DEPS)
	gcc -c $^

main: $(OBJS) $(DEPS)
	gcc -o $@ $^

.PHONY: clean

clean:
	rm $(OBJS) *.gch