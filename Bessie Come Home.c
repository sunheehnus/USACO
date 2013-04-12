/*
ID: sunheco1
LANG: C
TASK: comehome
*/
#include<stdio.h>

int P,result;

char pos;

int graph[55][55];

int cur[55],visit[55],exist[55];

int min()
{
	int m,i,find;
	m=1000000;
	find=0;
	for(i=1;i<=52;i++)
	{
		if(!visit[i]&&cur[i]<m)
		{
			m=cur[i];
			find=i;
		}
	}
	return find;
}

void Find(int i)
{
	int j,add,now;
	for(j=1;j<=52;j++)
	{
		visit[j]=0;
		cur[j]=graph[i][j];
	}
	visit[i]=1;
	while(1)
	{
		now=min();
		if(now==52)
		{
			if(cur[52]<result)
			{
				result=cur[52];
				pos=i-27+'A';
			}
			return;
		}
		visit[now]=1;
		add=cur[now];
		for(j=1;j<=52;j++)
		{
			if(!visit[j]&&graph[now][j]+add<cur[j])
				cur[j]=graph[now][j]+add;
		}
	}
}

int main()
{
	int i,j,l1,l2,lenth;
	char s1[2],s2[2];
	FILE *fin  = fopen ("comehome.in", "r");
    FILE *fout = fopen ("comehome.out", "w");
	result=100000;
	for(i=1;i<=54;i++)
	{
		for(j=1;j<=54;j++)
			graph[i][j]=1000000;
	}
	fscanf(fin,"%d",&P);
	for(i=0;i<P;i++)
	{
		fscanf(fin,"%s",s1);
		fscanf(fin,"%s",s2);
		fscanf(fin,"%d",&lenth);
	/*	if(*s1>='A'&&*s1<='Y'&&*s2>='A'&&*s2<='Y')
			continue;    */
		l1=*s1>='A'&&*s1<='Z'?*s1-'A'+27:*s1-'a'+1;
		l2=*s2>='A'&&*s2<='Z'?*s2-'A'+27:*s2-'a'+1;
		exist[l1]=exist[l2]=1;
		if(graph[l1][l2]>lenth)
			graph[l2][l1]=graph[l1][l2]=lenth;
	}
	for(i=27;i<=51;i++)
	{
		if(exist[i])
			Find(i);
	}
	fprintf(fout,"%c %d\n",pos,result);
	return 0;
}
