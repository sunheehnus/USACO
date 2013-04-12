/*
ID: sunheco1
LANG: C
TASK: ditch
*/
#include<stdio.h>

int n,m,s,t;

int map[256][256],level[256],cutoff[256],pre[256],queue[256];

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
		for(i=1;i<=n;i++)
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
	for(i=1;i<=n;i++)
	{
		if(map[now][i]&&level[i]+1==level[now])
			return i;
	}
	return 0;
}

int UpdataLevel(int now)
{
	int i,key=0x7fffffff;
	for(i=1;i<=n;i++)
	{
		if(map[now][i])
			key=key<level[i]+1?key:level[i]+1;
	}
	return key==0x7fffffff?n+1:key;
}

void MainAlgorithm()
{
	int i,j,key;
	Initialize();
	i=s;
	while(level[s]<=n)
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
			j=UpdataLevel(i);
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
	int st,ed,w,i;
	FILE *fin  = fopen ("ditch.in", "r");
    FILE *fout = fopen ("ditch.out", "w");
	fscanf(fin,"%d %d",&m,&n);
	for(i=1;i<=m;i++)
	{
		fscanf(fin,"%d %d %d",&st,&ed,&w);
		map[st][ed]+=w;
	}
	s=1;
	t=n;
	MainAlgorithm();
	fprintf(fout,"%d\n",flow);
	return 0;
}