#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

FILE *filein = fopen("/home/solork/repo/git/Novel.txt", "r");
	
void *freq_count(void *asda){
	char *opongono=(char *) asda;
	char string[500];
	int freq;
	printf("%s: ",opongono);
	if(filein==NULL) printf("hehe");
	while(!feof(filein)){
		fscanf(filein, "%s", string);
/*		int i;
		for(i=0; i<=4; i++){
			if(string[i]==opongono[i]) if(string[i+1]==opongono[i+1]) if(string[i+2]==opongono[i+2]) if(string[i+3]==opongono[i+3]) freq++;
			else break;
		}
*/		if(!strcmp(string, opongono)) freq++;
	}
	printf("%d\n", freq);
	sleep(1);
}

int main(int argc, char **argv){
	pthread_t t[argc];
	while(--argc){
		pthread_create(&t[argc], NULL, &freq_count, argv[argc]);
		pthread_join(t[argc], NULL);
	}
	return 0;
}
