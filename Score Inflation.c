/*
ID: sunheco1
LANG: C
TASK: inflate
*/
#include<stdio.h>

int time[11111],points[11111],minute[11111];

int main()
{
	int M,N,i,j,end;
	FILE *fin  = fopen ("inflate.in", "r");
    FILE *fout = fopen ("inflate.out", "w");
	fscanf(fin,"%d %d",&M,&N);
	for(i=1;i<=M;i++)
		minute[i]=-1;
	minute[0]=0;
	for(i=1;i<=N;i++)
	{
		fscanf(fin,"%d %d",points+i,time+i);
	}
	for(i=1;i<=N;i++)
	{
		end=M-time[i];
		for(j=0;j<=end;j++)
		{
			if(minute[j]!=-1&&(minute[j+time[i]]==-1||minute[j+time[i]]<points[i]+minute[j]))
			{
				minute[j+time[i]]=points[i]+minute[j];
			}
		}
	}
	for(i=1,j=0;i<=M;i++)
	{
		if(minute[i]>j)
			j=minute[i];
	}
	fprintf(fout,"%d\n",j);
	return 0;
}