#include <stdio.h>
#include "persona.h"

Lista insertar(Lista l, Nodo* n) {
	Lista aux;
	aux = (Lista)malloc(sizeof(Nodo));

	aux->p = n->p;
	aux->sig = l;

	return aux;
}

void consultar(Lista l) {
	Persona persona;

	while (l != NULL) {
		persona = (Persona*)l.p;
		printf("Nombre: %s\n",persona.nombre);
		l = l->sig;
	}
}