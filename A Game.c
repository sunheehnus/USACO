/*
ID: sunheco1
LANG: C
TASK: game1
*/
#include<stdio.h>

struct Judge{int max,min,visit;}map[111][111];

int tar[111];

int total;

void find(int s,int e)
{
	if(map[s][e].visit==1)
		return;
	if(s+1==e)
	{
		map[s][e].visit=1;
		map[s][e].max=tar[s]<tar[e]?tar[e]:tar[s];
		map[s][e].min=tar[s]<tar[e]?tar[s]:tar[e];
		return;
	}
	find(s+1,e);
	find(s,e-1);
	if(tar[s]+map[s+1][e].min<tar[e]+map[s][e-1].min)
	{
		map[s][e].max=tar[e]+map[s][e-1].min;
		map[s][e].min=map[s][e-1].max;
	}
	else
	{
		map[s][e].max=tar[s]+map[s+1][e].min;
		map[s][e].min=map[s+1][e].max;
	}
	map[s][e].visit=1;
}

int main()
{
	int i;
	FILE *fin  = fopen ("game1.in", "r");
    FILE *fout = fopen ("game1.out", "w");
	fscanf(fin,"%d",&total);
	for(i=1;i<=total;i++)
	{
		fscanf(fin,"%d",tar+i);
	}
	find(1,total);
	fprintf(fout,"%d %d\n",map[1][total].max,map[1][total].min);
	return 0;
}