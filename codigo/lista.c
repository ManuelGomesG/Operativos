#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista insertar(Lista l, void* e) {
	Lista temp = malloc(sizeof(Nodo));

	temp->info = e;
	temp->sig = l;

	return temp;
}

void consultar(Lista l) {
	printf("\n");
	if (l == NULL) {
		printf("Lista vacía.\n");
	} else {
		int i = 1;
		while (l != NULL) {
			printf("Nodo %d - %d\n",i,*(int*)l->info);
			l = l->sig;
			i++;
		}
	}
}

Lista eliminar(Lista l, void* e) {
	Lista l_temp = l;

	if (l_temp != NULL) {
		Nodo* temp;

		if (l_temp->info == e) {
			temp = l_temp->sig;
			l_temp->sig = NULL;
			free(l_temp);
			l = temp;
		} else {
			while (l_temp->sig != NULL) {
				if (l_temp->sig->info == e) {
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

Lista destruir(Lista l) {
	while (l != NULL) {
		l = eliminar(l,l->info);
	}
	return l;
}