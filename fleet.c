/*
MEMBERS
RICHA ANGADI PES2201800111
APOORVA CHOUDHARY PES2201800102
SECTION -D
*/

#include<stdio.h>
#include<stdlib.h>
#include"dijkstra.h"

int main(){

int choice;
printf("\n\n***************\t\tFLEET MANAGEMENT SYSTEM\t\t******************\n\n");
printf("Bus stops= 5\nNumber of buses= 3\n");
while(1)
{
	printf("Do you want to check  the cost?\nEnter 1 to check or 0 to exit\n");
	scanf("%d",&choice);
	if(choice==1)
		fleet();
	else
		break;
}
printf("\n******************\t\tTHANK YOU\t\t*****************\n");	
return 0;
}


