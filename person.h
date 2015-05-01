/*
Estructura de lista, y listas de listas.
Firmas de las funciones sobre listas.
*/


struct person
{
	char name[75];
	struct list *next;
	struct list *lfriends;
};

typedef struct person *list;
typedef struct person person;