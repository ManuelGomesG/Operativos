/*
PROYECTO 1 SISTEMAS OPERATIVOS I, ABRIL-JULIO 2015.
Grupo 30.
	Ricardo Münch. Carnet: 11-10684.
	Manuel Gomes. Carnet: 11-10375.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_p1.h"

/*----------------------------------------------------------------------------*/
/*Inserta a una persona en la lista*/
Lista insertar(Lista l, char *p) {
	Lista temp = (Lista) malloc(sizeof(Persona));

	temp->nombre = p;
	temp->amigos = NULL;
	temp->sig = l;

	return temp;
}

/*----------------------------------------------------------------------------*/
/*Calcula el tamaño de la lista*/
int tam(Lista l) {
	int n = 0;

	while (l != NULL) {
		n++;
		l = l->sig;
	}

	return n;
}

/*----------------------------------------------------------------------------*/
/*Elimina a una persona de la lista y libera la memoria asignada*/
Lista eliminar(Lista l, Persona *p) {
	Lista l_temp = l;

	if (l_temp != NULL) {
		Persona* temp;

		if (l_temp == p) {
			temp = l_temp->sig;
			l_temp->sig = NULL;
			free(l_temp->nombre);
			free(l_temp);
			l = temp;
		} else {
			while (l_temp->sig != NULL) {
				if (l_temp->sig == p) {
					temp = l_temp->sig->sig;
					l_temp->sig->sig = NULL;
					free(l_temp->sig->nombre);
					free(l_temp->sig);
					l_temp->sig = temp;
					break;
				}
				l_temp = l_temp->sig;
			}
		}
	}
	return l;
}

/*----------------------------------------------------------------------------*/
/*Libera la memoria de una lista de amigos*/
Persona *destruir_amigos(Persona *p) {
	Persona* temp;

	while (p != NULL) {
		temp = p->sig;
		p->sig = NULL;
		free(p);
		p = temp;
	}

	return p;
}

/*----------------------------------------------------------------------------*/
/*Libera la memoria asignada a la lista*/
Lista destruir(Lista l) {
	while(l != NULL) {
		l->amigos = destruir_amigos(l->amigos);
		l = eliminar(l,(Persona *)l);
	}
	return l;
}

/*----------------------------------------------------------------------------*/
/*Imprime una lista amigos*/
void imprimir_lineal(Lista l, FILE *fp) {
	if (l!= NULL) {
		while (l != NULL) {
			fprintf(fp, "%s ", (*l).nombre);
			l = l->sig;
		}
	}
}