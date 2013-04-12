/*
ID: sunheco1
LANG: C
TASK: holstein
*/
#include<stdio.h>

int v,g,cur,pertot;
int tar[33],now[33],step[33],root[33],vit[22][33];

int Judge()
{
	int i;
	for(i=1;i<=v;i++)
	{
		if(tar[i]>now[i])
			return 0;
	}
	return 1;
}

void store()
{
	int i;
	for(i=1;i<=cur;i++)
		root[i]=step[i];
	pertot=cur;
}

void Find(int ci)
{
	int j;
	if(cur<pertot-1&&ci<=g)
	{
		cur++;
		step[cur]=ci;
		for(j=1;j<=v;j++)
			now[j]+=vit[ci][j];
		if(Judge())
		{
			store();
			for(j=1;j<=v;j++)
				now[j]-=vit[ci][j];
			cur--;
			return;
		}
		Find(ci+1);
		for(j=1;j<=v;j++)
			now[j]-=vit[ci][j];
		cur--;
		Find(ci+1);
	}
}

int main()
{
	int i,j;
	FILE *fin  = fopen ("holstein.in", "r");
    FILE *fout = fopen ("holstein.out", "w");
	fscanf(fin,"%d",&v);
	for(i=1;i<=v;i++)
		fscanf(fin,"%d",tar+i);
	fscanf(fin,"%d",&g);
	for(i=1;i<=g;i++)
	{
		for(j=1;j<=v;j++)
			fscanf(fin,"%d",&vit[i][j]);
	}
	pertot=0xfffffff;
	Find(1);
	fprintf(fout,"%d",pertot);
	for(i=1;i<=pertot;i++)
		fprintf(fout," %d",root[i]);
	fprintf(fout,"\n");
	return 0;
}
