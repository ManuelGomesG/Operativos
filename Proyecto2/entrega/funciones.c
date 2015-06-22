/*
Taller de Sistemas Operativos I.
Abril-Julio 2015.
Proyecto 2.

Funciones a usar en main.c.

Hecho por:
	Ricardo Münch. Carnet: 11-10684.
	Manuel Gomes. Carnet: 11-10375.
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "funciones.h"

char *leerArchivo(char *archivo) {
	/* 
	   leerArchivo: lee el contenidode un archivo y
	   lo guarda en un string.

	   Parámetros:
	     - archivo: nombre del archivo a leer.
	*/

	FILE *fd = fopen(archivo,"r");

	fseek(fd, 0, SEEK_END);
	long tam = ftell(fd);
	fseek(fd, 0, SEEK_SET);

	char *texto = malloc(tam + 1);
	fread(texto, tam, 1, fd);
	fclose(fd);

	texto[tam] = 0;

	return texto;
}

char *concatenar(char *l1, char *l2) {
	/* 
	   concatenar: concatena dos strings en uno nuevo.

	   Parámetros:
	     - l1: primer string.
	     - l2: segundo string.
	*/

	char *r = malloc(strlen(l1) + strlen(l2) +1);
	strcpy(r, l1);
	strcat(r, l2);

	return r;
}