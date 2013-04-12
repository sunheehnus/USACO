/*
ID: sunheco1
LANG: C
TASK: stall4
*/
#include<stdio.h>

int n,m,s,t;

int map[512][512],level[512],cutoff[512],pre[512],queue[512];

int flow;

void Initialize()
{
	int s,e,tmp,i;
	level[t]=1;
	cutoff[1]=1;
	s=e=0;
	queue[++e]=t;
	while(s<e)
	{
		tmp=queue[++s];
		for(i=0;i<=511;i++)
		{
			if(level[i]==0&&map[i][tmp])
			{
				level[i]=level[tmp]+1;
				queue[++e]=i;
				cutoff[level[i]]++;
			}
		}
	}
}

int Find(int now)
{
	int i;
	for(i=0;i<=511;i++)
	{
		if(map[now][i]&&level[i]+1==level[now])
			return i;
	}
	return 0;
}

int UpdataLevel(int now,int total)
{
	int i,key=0x7fffffff;
	for(i=0;i<=511;i++)
	{
		if(map[now][i])
			key=key<level[i]+1?key:level[i]+1;
	}
	return key==0x7fffffff?total+1:key;
}

void MainAlgorithm(int total)
{
	int i,j,key;
	Initialize();
 	i=s;
	while(level[s]<=total)
	{
		j=Find(i);
		if(j)
		{
			pre[j]=i;
			i=j;
			if(i==t)
			{
				key=0x7fffffff;
				for(;i!=s;i=pre[i])
					key=key<map[pre[i]][i]?key:map[pre[i]][i];
				for(i=t;i!=s;i=pre[i])
				{
					map[pre[i]][i]-=key;
					map[i][pre[i]]+=key;
				}
				flow+=key;
			}
		}
		else
		{
			j=UpdataLevel(i,total);
			cutoff[level[i]]--;
			if(cutoff[level[i]]==0)
				return;
			cutoff[j]++;
			level[i]=j;
			if(i!=s)
				i=pre[i];
		}
	}
}

int main()
{
	int st,ed,cow,stall,i,j,k,ts;
	FILE *fin  = fopen ("stall4.in", "r");
    FILE *fout = fopen ("stall4.out", "w");
	fscanf(fin,"%d %d",&cow,&stall);
	s=0;
	t=511;
	for(i=1;i<=cow;i++)
	{
		map[0][i]=1;
	}
	for(i=1;i<=cow;i++)
	{
		fscanf(fin,"%d",&j);
		if(j==0)
			map[0][i]=0;
		for(k=1;k<=j;k++)
		{
			fscanf(fin,"%d",&ts);
			map[i][255+ts]=1;
			map[255+ts][511]=1;
		}
	}
	MainAlgorithm(cow+stall+2);
	fprintf(fout,"%d\n",flow);
	return 0;
}