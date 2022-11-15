#include <stdio.h>
#include <stdlib.h>

void writeFile(char*);
void copiaFile(char*, char*);

int main() {
	
	writeFile("principale.txt");
	copiaFile("principale.txt", "copia.txt");

	return 0;
}

void writeFile(char* nomeFile){
	FILE* file = NULL;
	char buf[30];
	
	file = fopen(nomeFile, "w");
	/*
	//ESCE QUADNO PREMI CTRL+D solo che su windows non funziona
	while(fgets(buf, sizeof(buf), stdin) != NULL  ){
        
        fputs(buf, file);
        
    }
	*/
	for (int i = 0; i < 5; ++i){
		printf("Cosa scrivo nel file?\n");
		gets(buf);
		fputs(buf, file);
	}

    fclose(file);

}

void copiaFile(char* nomeFile, char* nomeFileCopia){
	FILE* file = NULL;
	FILE* fileCopia =  NULL;
	char buf[30];

	file = fopen(nomeFile, "r");
	fileCopia = fopen(nomeFileCopia, "w");


	while(fgets(buf, sizeof(buf), file) != NULL) {
		fputs(buf, fileCopia);   
	}

	fclose(file);
	fclose(fileCopia);
}
