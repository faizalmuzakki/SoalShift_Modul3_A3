#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int statLohan=100, statKepiting=100;

void *lohan(void *){
	statLohan-=15;
	printf("Lohan Stat: %d", statLohan);
	sleep(10);
}

void *kepiting(void *){
	statKepiting-=10;
	printf("Kepiting Stat: %d", statKepiting);
	sleep(20);
}


void Feeding(void *){
	int food, hewan;
	printf("Makan?\n1. Lohan\n2. Kepiting\nYour Ans: ");
	scanf("%d", &hewan);
	if(hewan==1) statLohan+=10;
	else if(hewan==2) statKepiting+=10;
	else printf("Input sing nggenah!");
	sleep(1);
}

int main(){
	pthread_t t1, t2, t3;
	int anu1, anu2, anu3;
	anu1 = pthread_create(&t1, NULL, &lohan, NULL);
	anu2 = pthread_create(&t2, NULL, &kepiting, NULL);
	anu3 = pthread_create(&t1, NULL, &Feeding, NULL);
	pthread_join(t1, NULL);
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 
    if(statLohan<=0 || statKepiting<=0 || statLohan>100 ||statKepiting>100) return 0;
}
