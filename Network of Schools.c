/*
ID: sunheco1
LANG: C
TASK: schlnet
*/
#include<stdio.h>

int graph[128][128];
int sum[128];
int total;

int dfn[128],low[128],index;

int ggraph[128][128];
int gather[128];
int gtotal;
int gmap[128];

int finalgraph[128][128];
int finalsum[128];
int finaltotal;

int issource[128];
int sourcenum;
int issink[128];
int sinknum;

int isolatenum;

int asum,bsum;
/************************************************/
int stack[128],sp;
void push(int i)
{
	stack[++sp]=i;
}
int pop()
{
	return stack[sp--];
}
int exist(int i)
{
	int j;
	for(j=1;j<=sp;j++)
	{
		if(stack[j]==i)
			return 1;
	}
	return 0;
}
/************************************************/
int min(int a,int b)
{
	return a>b?b:a;
}

void tarjan(int u)
{
	int i;
	dfn[u]=low[u]=++index;
	push(u);
	for(i=1;i<=sum[u];i++)
	{
		if(dfn[graph[u][i]]==0)
		{
			tarjan(graph[u][i]);
			low[u]=min(low[u],low[graph[u][i]]);
		}
		else if(exist(graph[u][i]))
		{
			low[u]=min(low[u],dfn[graph[u][i]]);
		}
	}
	if(dfn[u]==low[u])
	{
		gtotal++;
		i=pop();
		while(i!=u)
		{
			gmap[i]=gtotal;
			i=pop();
		}
		gmap[u]=gtotal;
	}
}

int main()
{
	int i,j,tmp;
	FILE *fin  = fopen ("schlnet.in", "r");
    FILE *fout = fopen ("schlnet.out", "w");
	fscanf(fin,"%d",&total);
	for(i=1;i<=total;i++)
	{
		fscanf(fin,"%d",&tmp);
		while(tmp)
		{
			graph[i][++sum[i]]=tmp;
			fscanf(fin,"%d",&tmp);
		}
	}	
	for(i=1;i<=total;i++)
	{
		if(dfn[i]==0)
		{
			tarjan(i);
		}
	}
	
	for(i=1;i<=total;i++)
	{
		for(j=1;j<=sum[i];j++)
		{
			ggraph[gmap[i]][gmap[graph[i][j]]]=1;
		}
	}

	for(i=1;i<=total;i++)
	{
		for(j=1;j<=127;j++)
		{
			if(i!=j&&ggraph[i][j]==1)
			{
				finalgraph[i][++finalsum[i]]=j;
			}
		}
	}
	
	finaltotal=gtotal;
	
	for(i=1;i<=finaltotal;i++)
		issource[i]=1;
	for(i=1;i<=finaltotal;i++)
	{
		for(j=1;j<=finalsum[i];j++)
		{
			issource[finalgraph[i][j]]=0;
		}
	}
	for(i=1;i<=finaltotal;i++)
	{
		if(issource[i]==1)
			sourcenum++;
	}

	for(i=1;i<=finaltotal;i++)
		issink[i]=1;
	for(i=1;i<=finaltotal;i++)
	{
		if(finalsum[i]!=0)
			issink[i]=0;
	}
	for(i=1;i<=finaltotal;i++)
	{
		if(issink[i]==1&&issource[i]!=1)
			sinknum++;
		if(issink[i]==1&&issource[i]==1)
			isolatenum++;
	}
	asum=sourcenum;
	if(sinknum==0)
	{
		if(sourcenum==1)
			bsum=0;
		else
			bsum=sourcenum;
	}
	else
	{
		bsum=sinknum+isolatenum;
		if(bsum<sourcenum)
			bsum=sourcenum;
	}
	fprintf(fout,"%d\n%d\n",asum,bsum);
	return 0;
}