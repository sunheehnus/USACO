/*
ID: sunheco1
LANG: C
TASK: agrinet
*/
#include<stdio.h>

int farm[111][111];

int find[111],visit[111];

int N,result;

void search()
{
	int tar,j,min=100001;
	for(j=1;j<=N;j++)
	{
		if(!visit[j]&&find[j]<min)
		{
			min=find[j];
			tar=j;
		}
	}
	result+=min;
	visit[tar]=1;
	for(j=1;j<=N;j++)
	{
		if(!visit[j]&&farm[tar][j]<find[j])
		{
			find[j]=farm[tar][j];
		}
	}
}

int main()
{
	int i,j;
	FILE *fin  = fopen ("agrinet.in", "r");
    FILE *fout = fopen ("agrinet.out", "w");
	fscanf(fin,"%d",&N);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
			fscanf(fin,"%d",&farm[i][j]);
	}
	for(i=1;i<=N;i++)
		find[i]=farm[1][i];
	visit[1]=1;
	for(i=1;i<N;i++)
		search();
	fprintf(fout,"%d\n",result);
	return 0;
}