#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_p1.h"

int contar_lineas(const char *path) {
	FILE *fp = fopen(path,"r");
	char *linea = NULL;
	size_t n = 0;

	fp = fopen(path,"r");

	int num_l = 0;

	while (getline(&linea, &n, fp) != 1) {
		num_l++;
	}

	free(linea);
	fclose(fp);
	
	return num_l;
}

Lista leer_entrada(const char *path) {
	FILE *fp = fopen(path,"r");
	char *linea = NULL;
	size_t n = 0;
	Lista l = NULL;
	char *nombre_t;

	while (getline(&linea, &n, fp) != -1) {
		nombre_t = strtok(linea, " ");
		l = insertar(l, nombre_t);
		linea = NULL;

		nombre_t = strtok(NULL, " ");

		while (nombre_t = strtok(NULL, " \n")) {
			l->amigos = insertar(l->amigos, nombre_t);
		}
	}

	free(linea);
	fclose(fp);

	return l;
}