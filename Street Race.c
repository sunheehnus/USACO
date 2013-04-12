/*
ID: sunheco1
LANG: C
TASK: race3
*/
#include<stdio.h>
#include<string.h>

char map1[64][64],map2[64][64];

char visit[64],link[64];

char is1[64],is3[64];

int total,to,cnt1,cnt2;

int criticalnode[64],midnode[64];

int Judge(int now)
{
	int i,j,flag;
	memset(visit,0,sizeof(visit));
	memset(link,0,sizeof(link));
	visit[now]=1;
	link[0]=1;
	flag=1;
	while(flag)
	{
		flag=0;
		for(i=0;i<=total;i++)
		{
			if(link[i]==1&&visit[i]==0)
			{
				flag=1;
				visit[i]=1;
				for(j=0;j<=total;j++)
				{
					if(map1[i][j])
						link[j]=1;
				}
				if(link[total])
					return 0;
			}
		}
	}
	return 1;
}

void DFS1(int source,int sink)
{
	int i;
	if(is1[source])
		return;
	is1[source]=1;
	for(i=0;i<=total;i++)
	{
		if(map1[source][i]&&is1[i]==0)
		{
			if(i==sink)
			{
				is1[sink]=1;
				return;
			}
			else
				DFS1(i,sink);
		}
	}
}

void Find(int sink)
{
	int i,j,flag;
	memset(visit,0,sizeof(visit));
	is3[sink]=1;
	flag=1;
	while(flag)
	{
		flag=0;
		for(i=0;i<=total;i++)
		{
			if(is3[i]==1&&visit[i]==0)
			{
				flag=1;
				visit[i]=1;
				for(j=0;j<=total;j++)
				{
					if(map1[i][j])
						is3[j]=1;
				}
			}
		}
	}
}

int Yes(int sink)
{
	int i;
	memset(is1,0,sizeof(is1));
	memset(is3,0,sizeof(is3));
	DFS1(0,sink);
	Find(sink);
	for(i=0;i<=total;i++)
	{
		if(i!=sink&&is1[i]==is3[i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i;
	FILE *fin  = fopen ("race3.in", "r");
    FILE *fout = fopen ("race3.out", "w");
	for(;to!=-1;)
	{
		fscanf(fin,"%d",&to);
		if(to==-2)
		{
			total++; 
			continue;
		}
		map1[total][to]=1;
	}
	total--;
	for(i=1;i<total;i++)
	{
		if(Judge(i))
		{
			criticalnode[++cnt1]=i;
		}
	}
	for(i=1;i<=cnt1;i++)
	{
		if(Yes(criticalnode[i]))
		{
			midnode[++cnt2]=criticalnode[i];
		}
	}
	fprintf(fout,"%d",cnt1);
	for(i=1;i<=cnt1;i++)
		fprintf(fout," %d",criticalnode[i]);
	fprintf(fout,"\n");
	fprintf(fout,"%d",cnt2);
	for(i=1;i<=cnt2;i++)
		fprintf(fout," %d",midnode[i]);
	fprintf(fout,"\n");
	return 0;
}
