#include "person.h"
#include "stdio.h"


people create(){
	people ppl;
	ppl = malloc(sizeof(person));
	return ppl;
}

people getfriends(FILE *fp, list l){
	char *buffer[1000];
	fscanf(fp,"%s ", buffer);
	list->name = buffer;

}