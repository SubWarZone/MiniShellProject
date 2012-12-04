#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define tailleBuffer 100

int compterMots(char* chaine, char separateur) {
	int i = 0; int NbreMots = 0;
	for(i = 0; i < strlen(chaine)-1; i++) {
		if((chaine[i] != separateur) && (i == 0)) {
			NbreMots++;
		}
		
		else if((chaine[i] != separateur) && (chaine[i - 1] == separateur)) {
			NbreMots++;
		}  
	}
	return NbreMots;
}

char **separerLaChaine(char *chaine){
	int i = 0;
	char delims[] = " ";
	char *result = NULL;
	char **TousMesMots = malloc(15 * sizeof(char*)); // 15 cest nombre de mots
	
	result = strtok(chaine, delims );
	while(result != NULL) {
			printf("result is \"%s\"\n", result);
			TousMesMots[i] = malloc((strlen(result)) * sizeof(char));
			TousMesMots[i] = result; //&result[i]
			result = strtok(NULL, delims);
			i++;
	}
	return TousMesMots;
}

int main(int argc, char **argv)
{
	int NbreMots = 0;
	int i = 0;
	pid_t pid;
	int continuer=1;
	
	/* Pour le path */
	char *path;
	char **TousMesMots2 = malloc(15 * sizeof(char*));
	path=getenv("PATH");
	char delims2[] =":";
	
	printf("mon paths : %s\n",path);
	NbreMots = compterMots(path,':');
	printf ("nb mots dans le path : %d\n", NbreMots);
	
	path =  strtok (path,delims2);
	
	//*TEST GRAPHIQUE
	while( path != NULL ) {
		printf( "path is %s\n", path);
		TousMesMots2[i] = malloc((strlen(path)) * sizeof(char));
		TousMesMots2[i] = path; 
		path = strtok(NULL, delims2);
		i++;
	}

	while (continuer){
		char buffer[tailleBuffer];

		fgets(buffer,tailleBuffer,stdin);

		printf("ma chaine est : %s\n",buffer);
		
		NbreMots = compterMots(buffer, ' ');
		printf("notre chaine contient %d mots\n", NbreMots);
		
		char **TousMesMotsP = separerLaChaine(buffer);
		
		printf("le premier mot est: %s\n", TousMesMotsP[0]);
		printf("le deuxieme mot est: %s\n", TousMesMotsP[1]);
		printf("le troisieme mot est: %s\n", TousMesMotsP[2]);
		
/*	if(strcmp(TousMesMotsP[0], "exit ") == 0) {
			printf("les deux sont egaux\n");
			exit(1);
		}
		else {
			printf("bite et couille");
		}
*/		
		//char** parametres = {TousMesMots2[1], 
		/*
		if ((pid = fork()) == -1)
			perror("fork() error");
		else if (pid == 0) {
			execvp(TousMesMotsP[0], TousMesMots2);
			printf("Return not expected. Must be an execvp() error.\\n");
		}
		*/
	}
	return 0;
}
