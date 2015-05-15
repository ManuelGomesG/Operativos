#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
	system("clear");

	int i;

	i = contar_lineas(argv[1]);

	printf("\"%s\" tiene %d líneas\n", argv[1], i);

	return 0;
}