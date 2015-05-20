struct PERSONA {
	char *nombre;
	struct PERSONA *amigos;
	struct PERSONA *sig;
};

typedef struct PERSONA Persona;
typedef Persona *Lista;

struct TUPLA {
	char *p1;
	char *p2;
	Lista l1;
	Lista l2;
	struct TUPLA *sig;
};

typedef struct TUPLA Tupla;
typedef Tupla *Lista_t;

/*funciones de lista.c*/
Lista insertar(Lista, char *);
Lista eliminar(Lista, Persona *);
Lista destruir(Lista);
void imprimir_lineal(Lista, FILE *);
void imprimir(Lista);
void imprimir_amigos(Persona *);

/*funciones de lista_t.c*/
Lista_t insertar_t(Lista_t, char *, char *, Lista, Lista);
Lista_t eliminar_t(Lista_t, Tupla *);
Lista_t destruir_t(Lista_t);
void imprimir_tupla(Tupla, FILE *);
void imprimir_t(Lista_t, FILE *);

/*funciones para el main (funciones.c)*/
int contar_lineas(const char*);
Lista leer_entrada(const char*);
Lista_t Map(Persona *p);