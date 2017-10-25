#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int num;

void* factorial(void* fac)
{
int fac=1;
for(int a=1;a<=num;a++) 
{
fac=fac*a;
printf("Hasil %d! = %d\n",num, fac);
}
}




int main (int argc, char* argv[]){
    pthread_t thread[argc];
    int a, sommpen;
    
    for(a=1;a<argc;a++) {
    
    sommpen = atoi(argv[a])
    pthread_create(thread[a], NULL,&factorial,(void*)sommpen);
    }
    
    for(a=1;a<argc;a++){
    pthread_join(thread[a],NULL);
    }

}
