/*
ID: sunheco1
LANG: C
TASK: stamps
*/
#include<stdio.h>

char stamps[2][2222222],visit[2222222];

int map[555];

int main()
{
	int i,j,k,K,N,max,judge;
	char *ori,*tar,*temp;
	FILE *fin  = fopen ("stamps.in", "r");
    FILE *fout = fopen ("stamps.out", "w");
	ori=&stamps[1][0];
	tar=&stamps[0][0];
	fscanf(fin,"%d %d",&K,&N);
	max=0;
	for(i=1;i<=N;i++)
	{
		fscanf(fin,"%d",map+i);
		ori[map[i]]=1;
		tar[map[i]]=1;
		if(map[i]>max)
			max=map[i];
	}
	for(i=1,judge=max;i<K;i++,judge+=max)
	{
		for(j=1;j<=judge;j++)
		{
			if(!visit[j]&&ori[j]==1)
			{
				visit[j]=1;
				for(k=1;k<=N;k++)
				{
					tar[j+map[k]]=1;
				}
			}
		}
		for(j=1;j<=judge+max;j++)
			ori[j]=tar[j];
		temp=ori;
		ori=tar;
		tar=temp;
	}
	for(i=1;tar[i]==1;i++);
	fprintf(fout,"%d\n",i-1);
	return 0;
}