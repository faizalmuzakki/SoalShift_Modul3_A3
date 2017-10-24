#include <stdio.h>
#include <pthread.h>

int factorial(int a){
	if(a==0 || a==1) return 1;
	else return a*factorial(a-1);
}
int main(){
	printf("%d", factorial(3));
	return 0;
}
