#include <stdio.h>

struct NODO {
	void* p;
	struct NODO* sig;
};

typedef struct NODO Nodo;
typedef Nodo* Lista;

void insertar(Lista,Nodo*);
void consultar(Lista);