#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*Word Frequency Counter
 * Input harus satu-satu, contoh: ./cari Fina*/





FILE *filein = fopen("/home/solork/repo/git/Novel.txt", "r");
int j, k=0;

void *freq_count(void *asda){
	char *opongono=(char *) asda;
	char string[500];
	int freq[j];
	int anu;
	printf("%s: ",opongono);
	if(filein==NULL) printf("hehe");
	while(!feof(filein)){
		fscanf(filein, "%s", string);
		int i;
		for(anu=0; anu<500; anu++){
			if(string[anu]=='.' || string[anu]==',') string[anu]=' ';
		}
		printf("%s ", string);
		if(string[i]==opongono[i]) if(string[i+1]==opongono[i+1]) if(string[i+2]==opongono[i+2]) if(string[i+3]==opongono[i+3]) freq[k]++;
//		if(!strcmp(string, opongono)) freq[k]++;
	}
	printf("%d\n", freq[k]);
	k++;
	sleep(1);
}

int main(int argc, char **argv){
	pthread_t t[argc];
	j = argc;
	while(--argc){
		pthread_create(&t[argc], NULL, &freq_count, argv[argc]);
		pthread_join(t[argc], NULL);
	}
	
//	while(--j){
//	}
	return 0;
}
