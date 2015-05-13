#include <stdio.h>

typedef struct {
	char* nombre;
	ListaAmigos amigos;
} Persona;

typedef struct {
	Persona* p;
	struct Nodo* sig;
} Nodo;

typedef Nodo* ListaAmigos;
typedef Nodo* ListaPersonas;