#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_p1.h"

Lista insertar(Lista l, char *p) {
	Lista temp = malloc(sizeof(Persona));

	temp->nombre = p;
	temp->sig = l;

	return temp;
}

Lista eliminar(Lista l, Persona *p) {
	Lista l_temp = l;

	if (l_temp != NULL) {
		Persona* temp;

		if (l_temp == p) {
			temp = l_temp->sig;
			l_temp->sig = NULL;
			free(l_temp);
			l = temp;
		} else {
			while (l_temp->sig != NULL) {
				if (l_temp->sig == p) {
					temp = l_temp->sig->sig;
					l_temp->sig->sig = NULL;
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
}

Lista destruir(Lista l) {
	while(l != NULL) {
		l = eliminar(l,(Persona *)l);
	}
	return l;
}

void consultar_amigos(Persona *a) {
	if (a == NULL) {
		printf("-None-");
	} else {
		while (a != NULL) {
			printf("%s ", a->nombre);
			a = a->sig;
		}
	}
}

void consultar(Lista l) {
	if (l == NULL) {
		printf("Lista vacía.\n");
	} else {
		while (l != NULL) {
			printf("%s -> ", l->nombre);
			consultar_amigos(l->amigos);
			printf("\n");
			l = l->sig;
		}
	}
}