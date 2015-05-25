/*
PROYECTO 1 SISTEMAS OPERATIVOS I, ABRIL-JULIO 2015.
Grupo 30.
	Ricardo Münch. Carnet: 11-10684.
	Manuel Gomes. Carnet: 11-10375.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_p1.h"

/*----------------------------------------------------------------------------*/
/*Inserta en la última posición de la lista*/
Lista_t insertar_t(Lista_t l, char *P1, char *P2, Lista L1, Lista L2) {
	Lista_t temp = (Lista_t) malloc(sizeof(Tupla));

	temp->p1 = P1;
	temp->p2 = P2;
	temp->l1 = L1;
	temp->l2 = L2;
	temp->sig = NULL;

	if (l == NULL) {
		return temp;
	} else {
		Lista_t aux = l;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = temp;
		return l;
	}
}

/*----------------------------------------------------------------------------*/
/*Inserta en la posición correspondiente en orden alfabético*/
Lista_t insertar_t_en_orden(Lista_t l, char *P1, char *P2, Lista L1, Lista L2) {
	Lista_t next = l;
	Lista_t prev = l;
	Lista_t temp = (Lista_t) malloc(sizeof(Tupla));

	temp->p1 = P1;
	temp->p2 = P2;
	temp->l1 = L1;
	temp->l2 = L2;

	if (l == NULL) {
		temp->sig = NULL;
		return temp;
	} else {
		while (strcmp(temp->p1,next->p1) < 0) {
			prev = next;
			next = next->sig;
			if (next == NULL) break;
		}

		if ((next != NULL)&&(strcmp(temp->p1,next->p1) == 0)) {
			while ((strcmp(temp->p1,next->p1) == 0)&&(strcmp(temp->p2,next->p2) < 0)) {
				prev = next;
				next = next->sig;
				if (next == NULL) break;
			}
		}

		if (prev == next) {
			temp->sig = prev;
			prev = temp;
			return prev;
		} else {
			temp->sig = prev->sig;
			prev->sig = temp;
			return l;
		}
	}
}

/*----------------------------------------------------------------------------*/
/*Elimina una tupla de la lista sin liberar toda la memoria*/
Lista_t eliminar_t_light(Lista_t l, Tupla *p) {
	Lista_t l_temp = l;

	if (l_temp != NULL) {
		Tupla* temp;

		if (l_temp == p) {
			temp = l_temp->sig;
			l_temp->sig = NULL;
			free(l_temp);
			l = temp;
		} else {
			while (l_temp->sig != NULL) {
				if (l_temp->sig == p) {
					temp = l_temp->sig->sig;
					l_temp->sig->sig = NULL;
					free(l_temp->sig);
					l_temp->sig = temp;
					break;
				}
				l_temp = l_temp->sig;
			}
		}
	}
	return l;
}

/*----------------------------------------------------------------------------*/
/*Libera la memoria reservada por las tuplas (no libera los strings ni listas de 
personas)*/
Lista_t destruir_t_light(Lista_t l) {
	while(l != NULL) {
		l = eliminar_t_light(l,(Tupla *)l);
	}
	return l;
}

/*----------------------------------------------------------------------------*/
/*Elimina una tupla de la lista*/
Lista_t eliminar_t(Lista_t l, Tupla *p) {
	Lista_t l_temp = l;

	if (l_temp != NULL) {
		Tupla* temp;

		if (l_temp == p) {
			temp = l_temp->sig;
			l_temp->sig = NULL;
			free(l_temp->p1);
			free(l_temp->p2);
			destruir(l_temp->l1);
			free(l_temp);
			l = temp;
		} else {
			while (l_temp->sig != NULL) {
				if (l_temp->sig == p) {
					temp = l_temp->sig->sig;
					l_temp->sig->sig = NULL;
					free(l_temp->p1);
					free(l_temp->p2);
					destruir(l_temp->sig->l1);
					free(l_temp->sig);
					l_temp->sig = temp;
					break;
				}
				l_temp = l_temp->sig;
			}
		}
	}
	return l;
}

/*----------------------------------------------------------------------------*/
/*Libera la memoria reservada por las tuplas*/
Lista_t destruir_t(Lista_t l) {
	while(l != NULL) {
		l = eliminar_t(l,(Tupla *)l);
	}
	return l;
}

/*----------------------------------------------------------------------------*/
/*Imprime en un archivo una tupla con el formato del enunciado*/
void imprimir_tupla(Tupla t, FILE *fp) {
	fprintf(fp, "%s %s -> ", t.p1, t.p2);
	imprimir_lineal(t.l1, fp);
	if (t.l2 != NULL) {
		fprintf(fp, ", ");
		imprimir_lineal(t.l2, fp);
	}
	fprintf(fp ,"\n");
}

/*----------------------------------------------------------------------------*/
/*Imprime una lista de tuplas en un archivo*/
void imprimir_t(Lista_t l, FILE *fp) {
	if (l != NULL) {
		while (l != NULL) {
			imprimir_tupla((Tupla) *l, fp);
			l = l->sig;
		}
	}
}

/*----------------------------------------------------------------------------*/
/*Mezcla dos listas de tuplas ordenadas*/
Lista_t merge(Lista_t l1, Lista_t l2) {
	Lista_t temp, l = NULL;

	while (l1 != NULL && l2 != NULL) {
		if (strcmp(l1->p1, l2->p1) > 0) {
			if (l == NULL) {
				temp = l1;
				l1 = l1->sig;
				temp->sig = NULL;
				l = temp;
			} else {
				temp = l;
				while (temp->sig != NULL) {
					temp = temp->sig;
				}
				temp->sig = l1;
				l1 = l1->sig;
				temp->sig->sig = NULL;
			}
		} else if (strcmp(l1->p1, l2->p1) < 0) {
			if (l == NULL) {
				temp = l2;
				l2 = l2->sig;
				temp->sig = NULL;
				l = temp;
			} else {
				temp = l;
				while (temp->sig != NULL) {
					temp = temp->sig;
				}
				temp->sig = l2;
				l2 = l2->sig;
				temp->sig->sig = NULL;
			}
		} else {
			if (0 <= strcmp(l1->p2, l2->p2)) {
				if (l == NULL) {
					temp = l1;
					l1 = l1->sig;
					temp->sig = NULL;
					l = temp;
				} else {
					temp = l;
					while (temp->sig != NULL) {
						temp = temp->sig;
					}
					temp->sig = l1;
					l1 = l1->sig;
					temp->sig->sig = NULL;
				}
			} else {
				if (l == NULL) {
					temp = l2;
					l2 = l2->sig;
					temp->sig = NULL;
					l = temp;
				} else {
					temp = l;
					while (temp->sig != NULL) {
						temp = temp->sig;
					}
					temp->sig = l2;
					l2 = l2->sig;
					temp->sig->sig = NULL;
				}
			}
		}
	}

	if (l1 != NULL) {
		temp = l;
		if (temp != NULL) {
			while (temp->sig != NULL) {
				temp = temp->sig;
			}
			temp->sig = l1;
		} else {
			l = l1;
		}
	}

	if (l2 != NULL) {
		temp = l;
		if (temp != NULL) {
			while (temp->sig != NULL) {
				temp = temp->sig;
			}
			temp->sig = l2;
		} else {
			l = l2;
		}
	}

	return l;
}