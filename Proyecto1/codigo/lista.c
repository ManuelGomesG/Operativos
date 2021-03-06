#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_p1.h"

Lista insertar(Lista l, char *p) {
	Lista temp = (Lista) malloc(sizeof(Persona));

	temp->nombre = p;
	temp->amigos = NULL;
	temp->sig = l;

	return temp;
}

int tam(Lista l) {
	int n = 0;

	while (l != NULL) {
		n++;
		l = l->sig;
	}

	return n;
}

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

Lista destruir(Lista l) {
	while(l != NULL) {
		l->amigos = destruir_amigos(l->amigos);
		l = eliminar(l,(Persona *)l);
	}
	return l;
}

void imprimir_amigos(Persona *a) {
	if (a != NULL) {
		while (a != NULL) {
			printf("%s ", a->nombre);
			a = a->sig;
		}
	}
}

void imprimir_persona(Persona *p) {
	if (p != NULL) {
		printf("%s -> ", p->nombre);
		imprimir_amigos(p->amigos);
		printf("\n");
	}
}

void imprimir_lineal(Lista l, FILE *fp) {
	if (l!= NULL) {
		while (l != NULL) {
			fprintf(fp, "%s ", (*l).nombre);
			l = l->sig;
		}
	}
}

void imprimir(Lista l) {
	if (l == NULL) {
		printf("Lista vacía.\n");
	} else {
		while (l != NULL) {
			imprimir_persona((Persona *)l);
			l = l->sig;
		}
	}
}