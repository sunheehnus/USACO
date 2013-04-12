/*
ID: sunheco1
LANG: C
TASK: fence6
*/
#include<stdio.h>

int length[128],BFL[128],visit[128],connect[128][2][10];
int max,now,N;

int judge(int i,int j)
{
	int k;
	if(j==0)
		return 0;
	for(k=1;connect[i][0][k]!=0&&connect[i][0][k]!=j;k++);
	return connect[i][0][k]==0?0:1;
}

void Search(int i,int f)
{
	int j,temp;
	if(now+length[i]>=max)
		return;
	BFL[i]=now;
	now+=length[i];
	visit[i]=1;
	temp=judge(i,f);
	for(j=1;connect[i][temp][j];j++)
	{
		if(visit[connect[i][temp][j]]&&now-BFL[connect[i][temp][j]]<max)
			max=now-BFL[connect[i][temp][j]];
		else
			Search(connect[i][temp][j],i);
	}
	now-=length[i];
	visit[i]=0;
}

int main()
{
	int i,j,N1,N2,s;
	FILE *fin  = fopen ("fence6.in", "r");
    FILE *fout = fopen ("fence6.out", "w");
	fscanf(fin,"%d",&N);
	for(i=1;i<=N;i++)
	{
		fscanf(fin,"%d",&s);
		fscanf(fin,"%d",length+s);
		fscanf(fin,"%d",&N1);
		fscanf(fin,"%d",&N2);
		for(j=1;j<=N1;j++)
			fscanf(fin,"%d",&connect[s][0][j]);
		for(j=1;j<=N2;j++)
			fscanf(fin,"%d",&connect[s][1][j]);
	}
	max=0x7FFFFFFF;
	for(i=1;i<=N;i++)
	{
		Search(i,0);
	}
	fprintf(fout,"%d\n",max);
	return 0;
}