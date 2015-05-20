#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "header_p1.h"

int main(int argc, char *argv[]) {
	//system("clear");
	
	int n = atoi(argv[2]); //numero de procesos
	int npersonas = contar_lineas(argv[1]);
	
	if (npersonas < n) {
		n = npersonas;
	}

	int bloque = (npersonas + n - 1) / n;
	int residuo = npersonas % n;
	int p = bloque; //cant_p

	int i;
	int j;
	int status;
	FILE *fp;

	Lista l = leer_entrada(argv[1]);

	Persona *aux = l;
	Lista_t l_t = NULL;
	char archivo[10];
	pid_t hijos[n];


	for (i = 0; i < npersonas; i++) {
		if ((i + bloque -1) % bloque == 0) {
			if (residuo > 0) {
				p++;
				residuo--;
			}
			if ((hijos[i/bloque] = fork()) == 0) {
				sprintf(archivo, "%d.txt", getpid());
				fp = fopen(archivo, "w");
				
				for (j = 0; j < p; j++) {
					l_t = Map(aux);
					aux = aux->sig;

					imprimir_t(l_t, fp);
				}
				fclose(fp);
				exit(1);
			}
			for (j = 0; j < p; j++) {
				aux = aux->sig;
			}
			p = bloque;
		}
	}

	for (i = 0; i < n; i++) {
		wait(&status);
	}

	return 0;
}