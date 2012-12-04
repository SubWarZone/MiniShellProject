#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define tailleBuffer 100

int compterMots(char * chaine){
	int i=1;
	int compteur = 0;
	//nous 
	while(chaine[i] != '\0'){
		if(chaine[i] == ' ' && chaine[i-1] != ' '){	
				compteur++;
		}
		i++;
	}
	return compteur + 1; // il y a compteur espace et donc compter+1 mots
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
	int i = 0;
	pid_t pid;
	int continuer=1;
	
	/* Pour le path */
	char *path;
	char **TousMesMots2 = malloc(15 * sizeof(char*));
	path=getenv("PATH");
	char delims2[] =":";
	path =  strtok (path,delims2);
	
	//*TEST GRAPHIQUE
	while( path != NULL ) {
		printf( "path is \"%s\"\n", path);
		TousMesMots2[i] = malloc((strlen(path)) * sizeof(char));
		TousMesMots2[i] = path; 
		path = strtok(NULL, delims2);
		i++;
	}

	while (continuer){
		char buffer[tailleBuffer];

		fgets(buffer,tailleBuffer,stdin);

		printf("ma chaine est : %s\n",buffer);
		
		char **TousMesMotsP = separerLaChaine(buffer);
		
		printf("le premier mot est: %s\n", TousMesMotsP[0]);
		printf("le deuxieme mot est: %s\n", TousMesMotsP[1]);
		printf("le troisieme mot est: %s\n", TousMesMotsP[2]);
		
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
