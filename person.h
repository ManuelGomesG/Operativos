/*
Estructura de lista, y listas de listas.
Firmas de las funciones sobre listas.
*/
#include <stdio.h>

struct Person
{
	char name[75];
	struct Person *lnext; //Siguiente en la lista de amigos de una persona.
	struct Person *lfriends; // Listas de amigos de cada persona de la lista grande.
	struct Person *rnext; //Siguiente en la lista de listas (lista grande) .
};

typedef struct Person *list;
typedef struct Person person;

extern list create();
extern list getfriends(FILE *fp, list l);