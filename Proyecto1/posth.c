#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){


// int argc, char* argv[]

	FILE *fp = fopen("hola.txt", "r");
	char strings[2000];
	char *hola;
	int ch;
	int lines = 1; 
	int divi;
	int n = 2;
	while(!feof(fp)){
  		ch = fgetc(fp);
  		if(ch == '\n'){
    		lines++;
    			printf("%d\n", lines);
  	

  		}
	}

	divi=lines/n;


	pid_t childpid;
	int i;
	int status;

	for (i = 0; i < divi; i++){
		if ((childpid = fork()) < 0) {
 			perror("fork:");
	 		exit(1);
	 	}
	 	if (childpid==0){
	 		printf("hijo con pid: %ld\n", getpid() );
	 	}

	 	if (childpid!=0){
		 	for (i = 0; i < divi; ++i){
		 		wait(&status);
	 			printf("El padre termina\n");
		 	}
	 	}

	}

/*
	printf("%d\n",  divi );
	
	fp = fopen("hola.txt", "r");
	while (fgets(strings,sizeof(strings), fp)){

		printf("%s\n", strings);
	}
	return 0;
	*/
}