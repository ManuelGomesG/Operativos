#include <stdio.h>

int contar_lineas(const char *path) {
	FILE *fp = fopen(path,"r");
	int num_l = 0;
	char *line = NULL;
	size_t n = 0;


	while (getline(&line,&n,fp) > 0) {
		num_l++;
	}

	return num_l;
}