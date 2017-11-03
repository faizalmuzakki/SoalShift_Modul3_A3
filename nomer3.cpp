#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t t[3];
int statLohan=100, statKepiting=100, hewan;

void *lohan(void *){
	while(1){
		sleep(10);
		statLohan-=15;
	}
}

void *kepiting(void *){
	while(1){
		sleep(20);
		statKepiting-=10;
	}
}

void *feeding(void *){
	int hewan;
	printf("Status Lohan: %d\n", statLohan);
	printf("Status Kepiting: %d\n", statKepiting);
	printf("Beri makan?\n\t1. Lohan\n\t2. Kepiting\n");
	scanf("%d", &hewan);
	if(hewan==1) statLohan+=10;
	else if(hewan==2) statKepiting+=10;
	else printf("Input yang bener njeng\n");
}

int main(){
	pthread_t t[3];
	pthread_create(&t[0], NULL, &lohan, NULL);
	pthread_create(&t[1], NULL, &kepiting, NULL);
	while(1){
		system("clear");
		pthread_create(&t[2], NULL, &feeding, NULL);
		if(statKepiting > 100){
			printf("Kepiting kekenyangan, Si Kepiting mati :(\n");
			break;
		}
		if(statKepiting < 0){
			printf("Kepiting kelaparan, Si Kepiting mati :(\n");
			break;
		}
		if(statLohan > 100){
			printf("Lohan kekenyangan, Lohan mati :(\n");
			break;
		}
		if(statLohan < 0){
			printf("Kepiting kelaparan, Si Lohan mati :(\n");
			break;
		}
		sleep(1);
	}
	return 0;
}
