/*
PROYECTO 1 SISTEMAS OPERATIVOS I, ABRIL-JULIO 2015.
Grupo 30.
	Ricardo Münch. Carnet: 11-10684.
	Manuel Gomes. Carnet: 11-10375.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "header_p1.h"

/*----------------------------------------------------------------------------*/
/*Lee el archivo de entrada y construye la lista de personas*/
Lista leer_entrada(char *path) {
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

		while ((nombre_t = strtok(NULL, " \n"))) {
			if (strcmp(nombre_t,"-None-") == 0) {
				break;
			} else {
				l->amigos = insertar(l->amigos, nombre_t);
			}
		}
		printf("\n");
	}

	free(linea);
	fclose(fp);

	return l;
}

/*----------------------------------------------------------------------------*/
/*Lee tuplas de un archivo y construye una lista con ellas*/
Lista_t leer_tuplas(char *directorio, char* archivo) {
	char *path = malloc(sizeof(directorio)+sizeof(archivo)+2);
	path = strcpy(path,directorio);
	path = strcat(path,archivo);

	FILE *fp = fopen(path,"r");
	char *linea = NULL;
	size_t n = 0;
	Lista_t l_t = NULL;
	Tupla *aux;
	char *nombre1;
	char *nombre2;
	char *nombre_t;

	while (getline(&linea, &n, fp) != -1) {
		nombre1 = strtok(linea, " ");
		nombre2 = strtok(NULL, " ");

		l_t = insertar_t(l_t, nombre1, nombre2, NULL, NULL);

		aux = l_t;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}

		nombre_t = strtok(NULL, " ");
		linea = NULL;

		while ((nombre_t = strtok(NULL, " \n"))) {
			aux->l1 = insertar(aux->l1, nombre_t);
		}
	}

	free(path);
	free(linea);
	fclose(fp);

	return l_t;
}

/*----------------------------------------------------------------------------*/
/*Hace el mapping entre una persona y su lista de amigos*/
Lista_t Map(Persona *p) {
	Lista_t l = NULL;
	Lista aux = p->amigos;

	while (aux != NULL) {
		if (strcmp(p->nombre, aux->nombre) <= 0) {
			l = insertar_t_en_orden(l, p->nombre, aux->nombre, p->amigos, NULL);
		} else {
			l = insertar_t_en_orden(l, aux->nombre, p->nombre, p->amigos, NULL);
		}
		aux = aux->sig;
	}
	return l;
}

/*----------------------------------------------------------------------------*/
/*Distribuye entre una cantidad de procesos el mapping de una lista de personas*/
void map_procesos(Lista l, int nprocesos, int npersonas) {
	int tam_bloque,residuo,personas_hijo,i,j,pterminados,status;
	FILE *fp;
	Persona *aux;
	Lista_t l_t;
	char archivo[10];
	tam_bloque = npersonas / nprocesos;
	residuo = npersonas % nprocesos;

	if (tam_bloque == 1) {
		npersonas = nprocesos;
	} else if (tam_bloque == 0) {
		nprocesos = npersonas;
		tam_bloque = npersonas / nprocesos;
		residuo = 0;
	}

	pterminados = 0;
	personas_hijo = tam_bloque;
	aux = l;
	l_t = NULL;

	for (i = 0; i < npersonas; i++) {
		if ((i % tam_bloque == 0) && (pterminados < nprocesos)) {
			if (residuo > 0) {
				personas_hijo++;
				residuo--;
			}
			if (fork() == 0) {
				for (j = 0; j < personas_hijo; j++) {
					l_t = merge(l_t,Map(aux));
					aux = aux->sig;
				}

				sprintf(archivo, "datos/%d.txt", getpid());
				fp = fopen(archivo, "w");
				imprimir_t(l_t, fp);
				destruir_t_light(l_t);
				fclose(fp);
				exit(1);
			}

			for (j = 0; j < personas_hijo; j++) {
				if (aux != NULL) {
					aux = aux->sig;
				}
			}

			personas_hijo = tam_bloque;
			pterminados++;
		}
	}

	for (i = 0; i < nprocesos; i++) {
		wait(&status);
	}
}