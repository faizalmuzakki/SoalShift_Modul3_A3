#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>


void menu(){
	string weapon;
	int *amount[6]={20, 20, 20, 20, 20, 20};
	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    amount = shmat(shmid, NULL, 0);
	while(1){
		printf("---Applying menus for customer---\n");
		printf("1. Weapon List\n2. Buy Weapon\nYour input(1/2)?: ");
		scanf("%d", &i);
		if(i==1){
			if(amount[0]>0) printf("MP4A1 %d", amount[0]);
			else if(amount[1]>0) printf("PM2-V1 %d", amount[1]);
			else if(amount[2]>0) printf("SPR-3 %d", amount[2]);
			else if(amount[3]>0) printf("SS2-V5 %d", amount[3]);
			else if(amount[4]>0) printf("SPG1-V3 %d", amount[4]);
			else if(amount[5]>0) printf("MINE %d", amount[5]);
		
		}
		else if(i==2){
			printf("Your input?(Syntax: 'Weapon_name Amount'\n");
			scanf("%s%d", &weapon, &i);
			if(strcmp(weapon, "MP4A1")==0) amount[0]-=i;
			if(strcmp(weapon, "PM2-V1")==0) amount[1]-=i;
			if(strcmp(weapon, "SPR-3")==0) amount[2]-=i;
			if(strcmp(weapon, "SS2-V5")==0) amount[3]-=i;
			if(strcmp(weapon, "SPG1-V3")==0) amount[4]-=i;
			if(strcmp(weapon, "MINE")==0) amount[5]-=i;
		}
		else return;
	}
}

int main(){
	menu();
	return 0;
}
