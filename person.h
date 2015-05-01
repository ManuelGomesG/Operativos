/*
Estructura de lista, y listas de listas.
Firmas de las funciones sobre listas.
*/


struct person
{
	char name[75];
	struct person *lnext;
	struct person *lfriends;
	struct person *rnext;
};

typedef struct person *list;
typedef struct person person;