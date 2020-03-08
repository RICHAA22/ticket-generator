#include<stdio.h>
#include<stdlib.h>
#include "dijkstra.h"

										/*       FUNCTION DEFINITION FILE         */

//the dijkstra algorithm to find out the shortest path between any two vertices/points.
int dijkstra(int G[MAX][MAX],int n,int startnode,int end)
{

	int dist[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;

	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the dist matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				dist[i][j]=INFINITY;
			else
				dist[i][j]=G[i][j];

	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=dist[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1)
	{
		mindistance=INFINITY;

		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}

			//check if a better path exists through nextnode
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+dist[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+dist[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	//calculates the cost for every bus
	for(i=0;i<n;i++)
		if(i==end)
		{
			return distance[i]*fixed_rate;
		}

}

//function where the user enters the bus stop, he/she wishes to reach in minimal cost
void fleet(){
int c1,c2,c3,min;
int n=5; //no of stops
int source,destin;

int bus1[MAX][MAX]={{0,1,0,3,10},{1,0,5,0,0},{0,5,0,2,1},{3,0,2,0,6},{10,0,1,6,0}};
int bus2[MAX][MAX]={{0,1,0,2,5},{1,0,2,0,0},{0,2,0,3,0},{2,0,3,0,4},{5,0,0,4,0}};
int bus3[MAX][MAX]={{0,3,5,3,0},{3,0,5,0,0},{5,5,0,5,0},{3,0,5,0,5},{0,0,0,5,0}};

printf("Enter\n'0' for place A\n'1' for place B\n'2' for place C\n'3' for place D\n'4' for place E\n");
		printf("Enter your starting point: ");
		scanf("%d", &source);
		printf("Enter your destination: ");
		scanf("%d", &destin);
		if(source>=0 && source<5 && destin>=0 && destin<5 )
		{
		c1=dijkstra(bus1,n,source,destin);
		c2=dijkstra(bus2,n,source,destin);
		c3=dijkstra(bus3,n,source,destin);
		printf("Cost for bus1 is %d\n",c1);
		printf("Cost for bus2 is %d\n",c2);
		printf("Cost for bus3 is %d\n",c3);
		min= min_cost(c1,c2,c3);
		}
		else
			printf("Not a valid input\n");
}

  //to find which bus has the minimum cost amongst the 3 buses
int min_cost(int a, int b, int c)
{
	int arr[3]={a,b,c};
	int i, min=a;
	for(i=0;i<3;i++)
		if(min>arr[i])
			min=arr[i];
	printf("The user could use ");	
	for(i=0;i<3;i++)
		if(min==arr[i])
		{
			printf("Bus%d ,",i+1);
			continue;
		}
		
	printf("\b and the cost will be %d\n",min);
return 0;		
}