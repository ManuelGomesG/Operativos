typedef struct NODO {
	void* info;
	struct NODO* sig;
} Nodo;

typedef struct NODO* Lista;

void consultar(Lista);
Lista insertar(Lista,void*);
Lista eliminar(Lista,void*);
Lista destruir(Lista);