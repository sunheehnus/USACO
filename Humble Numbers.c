/*
ID: sunheco1
LANG: C
TASK: humble
*/
#include<stdio.h>

int result[111111];

int prime[111],now[111];

int main()
{
	int total,rank,i,j,min;
	FILE *fin  = fopen ("humble.in", "r");
    FILE *fout = fopen ("humble.out", "w");
	fscanf(fin,"%d %d",&total,&rank);
	for(i=1;i<=total;i++)
		fscanf(fin,"%d",prime+i);
	result[0]=1;
	for(j=1;j<=rank;j++)
	{
		min=0x7FFFFFFF;
		for(i=1;i<=total;i++)
		{
			if(prime[i]*result[now[i]]<min)
				min=prime[i]*result[now[i]];
		}
		for(i=1;i<=total;i++)
		{
			if(prime[i]*result[now[i]]==min)
				(now[i])++;
		}
		result[j]=min;
	}
	fprintf(fout,"%d\n",min);
	return 0;
}
