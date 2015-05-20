#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_p1.h"

Lista_t insertar_t(Lista_t l, char *P1, char *P2, Lista L1, Lista L2) {
	Lista_t temp = (Lista_t) malloc(sizeof(Tupla));

	temp->p1 = P1;
	temp->p2 = P2;
	temp->l1 = L1;
	temp->l2 = L2;
	temp->sig = l;

	return temp;
}

Lista_t eliminar_t(Lista_t l, Tupla *p) {
	Lista_t l_temp = l;

	if (l_temp != NULL) {
		Tupla* temp;

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

Lista_t destruir_t(Lista_t l) {
	while(l != NULL) {
		l = eliminar_t(l,(Tupla *)l);
	}
	return l;
}

void imprimir_tupla(Tupla t, FILE *fp) {
	fprintf(fp, "(%s %s) -> ", t.p1, t.p2);
	imprimir_lineal(t.l1, fp);
	if (t.l2 != NULL) {
		fprintf(fp, ", ");
		imprimir_lineal(t.l2, fp);
	}
	fprintf(fp ,"\n");
}

void imprimir_t(Lista_t l, FILE *fp) {
	if (l == NULL) {
		fprintf(fp, "Lista vacía.\n");
	} else {
		while (l != NULL) {
			imprimir_tupla((Tupla) *l, fp);
			l = l->sig;
		}
	}
}