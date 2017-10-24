#include <stdio.h>
#include <pthread.h>

void *freq_count(void *asda){
	char opongono[10]=(void *)asda;
	FILE* filein;
	filein = fopen("/home/solork/git/Novel.txt", r);
}

int main(int argc, int *argv[]){
	pthread_t t[argc];
	while(--argc){
		pthread_create(&t[argc], NULL, &freq_count, NULL);
		pthread_join(t[argc], NULL);
	}
}
