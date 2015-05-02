#include <stdio.h>
#include "person.h"

int main()
{
	FILE *fp;
	char *h[75];

	fp=fopen("hola.txt", "r");
	list hola;
	hola=create();
	getfriends(fp, hola);

	printf("%s\n", hola->name );

	return 0;
}