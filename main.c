#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

}

int runcmd(char *cmd)
{
	pid_t child_pid;
	int child_status;

	child_pid = fork();
	if(child_pid == 0) {
		/* This is done by the child process. */

		execvp(argv[0], argv);

		/* If execvp returns, it must have failed. */

		printf("Unknown command\n");
		exit(0);
	}
	else {
		/* This is run by the parent.  Wait for the child
		to terminate. */

		do {
			pid_t tpid = wait(&child_status);
			if(tpid != child_pid) process_terminated(tpid);
		}while(tpid != child_pid);

		return child_status;
	
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	int continuer=1;
	char delims[] = " ";
	char *result = NULL;
	char *TousMesMots = malloc(15 * sizeof(char)); // 15 cest nombre de mots

	while (continuer){
		char buffer[tailleBuffer];

		fgets(buffer,tailleBuffer,stdin);

		printf("ma chaine est : %s\n",buffer);

		result = strtok(buffer, delims );
		while( result != NULL ) {
			printf( "result is \"%s\"\n"", result);
			TousMesMots[i] = malloc((strlen(result)) * sizeof(char));
			TousMesMots[i] = result; //&result[i]
			result = strtok(NULL, delims);
			i++;
		}

		printf("le troisieme mot est: %s", TousMesMots[2]);
	}

	return 0;
}
