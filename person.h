/*
Estructura de lista, y listas de listas.
Firmas de las funciones sobre listas.
*/


struct person
{
	char name[75];
	struct list *next;
	struct list *friends;
};

typedef struct person *people;
typedef struct person person;