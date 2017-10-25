#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

FILE *filein;

int k=0, j;

void *freq_count(void *asda){
	filein=fopen("/home/solork/repo/git/Novel.txt", "r");
	char *opongono=(char *) asda;
	char string[2000];
	int temp[j];
	for(int b=0; b<j; b++) temp[b] = 0;
	int anu;
	if(filein==NULL) printf("hehe");
	while(!feof(filein)){
		fscanf(filein, "%s", string);
		int i;
		for(anu=0; anu<500; anu++){
			if(string[anu]=='.' || string[anu]==',') string[anu]='\0';
		}
		if(!strcmp(string, opongono)){
			temp[k]++;
		}
	}
	if(k>=0) temp[k]-=temp[k-1];
	printf("%s: ",opongono);
	printf("%d\n", temp[k]);
	k++;
}

int main(int argc, char **argv){
	pthread_t t[argc];
	j=argc;
	while(--argc){
		pthread_create(&t[argc], NULL, &freq_count, argv[argc]);
		pthread_join(t[argc], NULL);
	}
	
//	while(--j){
//	}
	return 0;
}

