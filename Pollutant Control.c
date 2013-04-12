/*
ID: sunheco1
LANG: C
TASK: milk6
*/
#include<stdio.h>
#include<string.h>
struct Route{int s,e,c;};

int N,M;

struct Route route[1024];

int original[36][36],map1[36][36],cnt[36][36],start[36][36],level[36],cutoff[36],pre[36],queue[36],visit[36];

int max,total,flag;

int critical[1024],left[1024],tot[1024]; 

long long map[36][36],flow;

void Initialize()
{
	int s,e,tmp,i;
	memset(level,1,sizeof(level)); 
	level[N]=0;
	cutoff[0]=1;
	s=e=0;
	queue[++e]=N;
	while(s<e)
	{
		tmp=queue[++s];
		for(i=1;i<=N;i++)
		{
			if(level[i]>=N&&map[i][tmp])
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
	for(i=1;i<=N;i++)
	{
		if(map[now][i]&&level[i]+1==level[now])
			return i;
	}
	return 0;
}

int UpdataLevel(int now)
{
	int i,key=16843009;
	for(i=1;i<=N;i++)
	{
		if(map[now][i])
			key=key<level[i]+1?key:level[i]+1;
	}
	return key==16843009?N:key;
}

void MainAlgorithm()
{
	int i,j;
	long long key;
	Initialize();
	i=1;
	while(level[1]<N)
	{
		j=Find(i);
		if(j)
		{
			pre[j]=i;
			i=j;
			if(i==N)
			{
				key=0x7fffffff;
				for(;i!=1;i=pre[i])
					key=key<map[pre[i]][i]?key:map[pre[i]][i];
				for(i=N;i!=1;i=pre[i])
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
			cutoff[j]++;
			cutoff[level[i]]--;
			if(cutoff[level[i]]==0)
				return;	
			level[i]=j;
			if(i!=1)
				i=pre[i];
		}
	}
}

void DFS(int now)
{
	int i;
	for(i=1;i<=N;i++)
	{
		if(!visit[i]&&map1[now][i]==0&&original[now][i])
		{
			visit[i]=1;
			DFS(i);
		}
	}
}

int Judge()
{
	memset(visit,0,sizeof(visit));
	visit[1]=1;
	DFS(1);
	if(visit[N]==0)
		return 1;
	return 0;
}

void DFSID(int now,int level,int next)
{
	int i;
	if(now>level)
	{
		if(max==0&&Judge())
		{
			flag=1;	
		}
		return;
	}
	for(i=next;i<=total;i++)
	{
		if(flag)
			return;
		if(max>left[i]||tot[i]+now-1<level)
   			return;
		if(map1[route[critical[i]].s][route[critical[i]].e]==1||start[route[critical[i]].s][route[critical[i]].e]<i||(level-now+1<cnt[route[critical[i]].s][route[critical[i]].e])||max-original[route[critical[i]].s][route[critical[i]].e]<0)
			continue;
		map1[route[critical[i]].s][route[critical[i]].e]=1;
		max-=original[route[critical[i]].s][route[critical[i]].e];
		DFSID(now+cnt[route[critical[i]].s][route[critical[i]].e],level,i+1);
		if(flag)
			return;
		map1[route[critical[i]].s][route[critical[i]].e]=0;
		max+=original[route[critical[i]].s][route[critical[i]].e];
	}
}

int main()
{
	int i,j;
	FILE *fin  = fopen ("milk6.in", "r");
    FILE *fout = fopen ("milk6.out", "w");
	fscanf(fin,"%d %d",&N,&M);
	for(i=1;i<=M;i++)
	{
		fscanf(fin,"%d %d %d",&route[i].s,&route[i].e,&route[i].c);
		map[route[i].s][route[i].e]+=route[i].c*1001+1;
		original[route[i].s][route[i].e]+=route[i].c;
		cnt[route[i].s][route[i].e]++;
	}
	MainAlgorithm();
	max=flow/1001;
	if(max==0)
	{
		fprintf(fout,"%d %d\n",0,0);
		return 0;
	}
	for(i=1,total=0;i<=M;i++)
	{
		if(map[route[i].s][route[i].e]==0)
		{
			critical[++total]=i;
		}
	}
	for(i=1;i<=total;i++)
	{
		if(start[route[critical[i]].s][route[critical[i]].e]==0)
		{
			start[route[critical[i]].s][route[critical[i]].e]=i;
		}	
	}
	for(i=1,tot[0]=total;i<=total;i++)
	{
		if(start[route[critical[i]].s][route[critical[i]].e]==i)
			tot[i]=tot[i-1]-cnt[route[critical[i]].s][route[critical[i]].e];
		else
			tot[i]=tot[i-1];
	}
	for(i=1;i<=total;i++)
	{
		if(start[route[critical[i]].s][route[critical[i]].e]==i)
			tot[i]+=cnt[route[critical[i]].s][route[critical[i]].e];
	}
	for(i=1;i<=total;i++)
	{
		left[0]+=route[critical[i]].c;
	}
	for(i=1;i<=total;i++)
	{
		if(start[route[critical[i]].s][route[critical[i]].e]==i)
			left[i]=left[i-1]-route[critical[i]].c;
		else
			left[i]=left[i-1];
	}
	for(i=1;i<=total;i++)
	{
		if(start[route[critical[i]].s][route[critical[i]].e]==i)
			left[i]+=route[critical[i]].c;
	}
	DFSID(1,flow%1001,1);
	fprintf(fout,"%lld %lld\n",flow/1001,flow%1001);
	for(i=1;i<=total;i++)
	{
		if(map1[route[critical[i]].s][route[critical[i]].e]==1)
			fprintf(fout,"%d\n",critical[i]);
	}
	return 0;
}
