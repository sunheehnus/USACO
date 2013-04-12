/*
ID: sunheco1
LANG: C
TASK: bigbrn
*/   
#include<stdio.h>

short farm[1024][1024];

int N,T;

int exist(int x,int y,int size)
{
	int i;
	if(x+size<=N&&y+size<=N)
	{
		for(i=0;i<=size;i++)
		{
			if(farm[x+size][y+i]==-1)
				return 0;
		}
		for(i=0;i<=size;i++)
		{
			if(farm[x+i][y+size]==-1)
				return 0;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

int compute(int x,int y,int size)
{
	while(exist(x,y,size))
	{
		size++;
	}
	return size;
}

int maxsize(int x,int y)
{
	int size=1;
	if(y>1&&farm[x][y-1]-1>size)
	{
		size=farm[x][y-1]-1;
	}
	if(x>1&&farm[x-1][y]-1>size)
	{
		size=farm[x-1][y]-1;
	}
	return compute(x,y,size);
}

int main()
{
	int x,y,i,j,max;
	FILE *fin  = fopen ("bigbrn.in", "r");
    FILE *fout = fopen ("bigbrn.out", "w");
	fscanf(fin,"%d %d",&N,&T);
	for(i=0;i<T;i++)
	{
		fscanf(fin,"%d %d",&x,&y);
		farm[x][y]=-1;
	}
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(farm[i][j]!=-1)
			{
				farm[i][j]=maxsize(i,j);
			}
		}
	}
	max=0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(farm[i][j]>max)
				max=farm[i][j];
		}
	}
	fprintf(fout,"%d\n",max);
	return 0;
}