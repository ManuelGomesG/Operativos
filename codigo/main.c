#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "header_p1.h"

main(int argc, char *argv[]) {
	Lista l;
	int num_p = (int) strtol(argv[1], NULL, 10);

	int i;
	Persona *aux = l;

	pid_t hijo;

	system("clear");
	l = leer_entrada(argv[2]);
	//imprimir_lista(l);

	//for ()

	l = destruir(l);
}