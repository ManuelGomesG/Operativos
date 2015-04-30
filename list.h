/*
Estructura de lista, y listas de listas.
Firmas de las funciones sobre listas.
*/


struct list
{
	char name[75];
	struct list *next;
	struct list *friends;
};

typedef struct list *people;
typedef struct list person;