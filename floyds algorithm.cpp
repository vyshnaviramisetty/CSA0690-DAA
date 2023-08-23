#include<stdio.h>
#include<limits.h>
#define v 4
void floyd(int graph[v][v])
{
	int dist[v][v];
	for(int i=0;i<v;i++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				dist[i][j]=graph[i][j];
			}
		}
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			for(int k=0;k<v;k++)
			{
				if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printf("shortest distance between all pairs of vetrices:\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(dist[i][j]==INT_MAX)
			{
				printf("INF\t");
			}
			else
			{
				printf("%d\t",dist[i][j]);
			}
		}
		printf("\n");
	}
}
main()
{
	int graph[v][v]={{0,5,INT_MAX,10},{INT_MAX,0,3,INT_MAX},{INT_MAX,INT_MAX,0,1},{INT_MAX,INT_MAX,INT_MAX,0}};
	floyd(graph);
}
