/*
ID: sunheco1
LANG: C
TASK: concom 
*/
#include<stdio.h>

int company[111][111],control[111][111];

int total,thistime;

void Init()
{
	int i,j;
	for(i=1;i<=100;i++)
	{
		for(j=1;j<=100;j++)
		{
			if(control[i][j]==100)
				total++;
		}
	}
}

void Find(int i,int j)
{
	int k;
	for(k=1;k<=100;k++)
	{
		if(control[i][k]!=100)
			control[i][k]+=company[j][k];
	}
}

int main()
{
	int i,j,s,e,sos,tot;
	FILE *fin  = fopen ("concom.in", "r");
    FILE *fout = fopen ("concom.out", "w");
	fscanf(fin,"%d",&tot);
	for(i=0;i<tot;i++)
	{
		fscanf(fin,"%d %d %d",&s,&e,&sos);
		company[s][e]=sos;
		if(sos>50)
			control[s][e]=100;
	}
	while(1)
	{
		thistime=0;
		for(i=1;i<=100;i++)
		{
			for(j=1;j<=100;j++)
			{
				if(control[i][j]!=100)
					control[i][j]+=company[i][j];
			}
			for(j=1;j<=100;j++)
			{
				if(i!=j&&control[i][j]==100)
				{
					Find(i,j);
				}
			}
		}
		for(i=1;i<=100;i++)
		{
			for(j=1;j<=100;j++)
			{
				if(control[i][j]>50)
				{
					control[i][j]=100;
					thistime++;
				}
				else
					control[i][j]=0;
			}
		}
		if(thistime==total)
			break;
		total=thistime;
	}
	for(i=1;i<=100;i++)
	{
		for(j=1;j<=100;j++)
		{
			if(i!=j&&control[i][j]==100)
			{
				fprintf(fout,"%d %d\n",i,j);
			}
		}
	}
	return 0;
}