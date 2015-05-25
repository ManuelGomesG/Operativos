/*
PROYECTO 1 SISTEMAS OPERATIVOS I, ABRIL-JULIO 2015.
Grupo 30.
	Ricardo Münch. Carnet: 11-10684.
	Manuel Gomes. Carnet: 11-10375
*/

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
int tam(Lista);
Lista eliminar(Lista, Persona *);
Lista destruir(Lista);
void imprimir_persona(Persona *);
void imprimir_lineal(Lista, FILE *);
void imprimir(Lista);
void imprimir_amigos(Persona *);

/*funciones de lista_t.c*/
Lista_t insertar_t(Lista_t, char *, char *, Lista, Lista);
Lista_t insertar_t_en_orden(Lista_t, char *, char *, Lista, Lista);
Lista_t eliminar_t_light(Lista_t, Tupla *);
Lista_t destruir_t_light(Lista_t);
Lista_t eliminar_t(Lista_t, Tupla *);
Lista_t destruir_t(Lista_t);
void imprimir_tupla(Tupla, FILE *);
void imprimir_t(Lista_t, FILE *);
Lista_t merge(Lista_t l1, Lista_t l2);

/*funciones para el main (funciones.c)*/
Lista leer_entrada(char*);
Lista_t leer_tuplas(char*, char*);
Lista_t Map(Persona *p);
void map_procesos(Lista, int, int);