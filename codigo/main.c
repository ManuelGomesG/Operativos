#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "header_p1.h"

main(int argc, char *argv[]) {
	system("clear");
	Lista l;

	l = leer_entrada("./datos/entrada");
	consultar(l);

	//l = destruir(l);
	//consultar(l);	
}