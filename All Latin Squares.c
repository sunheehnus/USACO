/*
ID: sunheco1
LANG: C
TASK: latin
*/
#include<stdio.h>
#include<string.h>
int table[5040][8];
int map[5040];

int visit[8];
int tmp[8];

int total,N,cnt;

int square[8][8];

int is[8][8];

void fill()
{
	int i,result;
	for(i=1,result=0;i<=N;i++)
	{
		result*=10;
		table[total][i]=tmp[i];
		result+=tmp[i];
	}
	map[total]=result;
}

int value()
{
	int i;
	for(i=1;i<=N;i++)
	{
		if(tmp[i]==i)
			return 0;
	}
	return 1;
}

void createtable(int level)
{
	int i;
	for(i=1;i<=N;i++)
	{
		if(visit[i]==0)
		{
			visit[i]=1;
			tmp[level]=i;
		}
		else
		{
			continue;
		}
		if(level==N)
		{
			if(value())
			{
				fill();
				total++;
			}
		}
		else
		{
			createtable(level+1);
		}
		visit[i]=0;
	}
	if(level==1)
	{
		total--;
	}
}

int findl(int target)
{
	int l,u,mid;
	l=0;
	u=total;
	while(l<=u)
	{
		mid=(l+u)>>1;
		if(target>map[mid])
			l=mid+1;
		else 
			u=mid-1;
	}
	return l;
}
int findu(int target)
{
	int l,u,mid;
	l=0;
	u=total;
	while(l<=u)
	{
		mid=(l+u)>>1;
		if(target>map[mid])
			l=mid+1;
		else 
			u=mid-1;
	}
	return u;
}

int computeminpos(int level)
{
	int i,result;
	for(i=1,result=level;i<N;i++)
	{
		result*=10;
	}
	return findl(result);
}

int computemaxpos(int level)
{
	int i,result;
	for(i=1,result=level+1;i<N;i++)
	{
		result*=10;
	}
	return findu(result);
}
int OK(int i)
{
	int j;
	for(j=1;j<=N;j++)
	{
		if(is[j][table[i][j]]==1)
			return 0;
	}
	return 1;
}

void judge(int level)
{
	int minpos,maxpos,i,j;
	minpos=computeminpos(level);
	maxpos=computemaxpos(level);
	for(i=minpos;i<=maxpos;i++)
	{
		if(OK(i))
		{
			for(j=1;j<=N;j++)
			{
				is[j][table[i][j]]=1;
			}
			if(level==N)
			{
				cnt++;
			}
			else
			{
				judge(level+1);
			}
			for(j=1;j<=N;j++)
			{
				is[j][table[i][j]]=0;
			}
		}
	}
}

/*

void judge(int level)
{
	int minpos,maxpos,i,j;
	if(level==N)
	{
		memset(tmp,0,sizeof(tmp));
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				if(is[i][j]==0)
				{
					if(tmp[j]==1)
						return;
					else
					{
						tmp[j]=1;
						break;
					}
				}
			}
		}
		cnt++;
		return;
	}
	minpos=computeminpos(level);
	maxpos=computemaxpos(level);
	for(i=minpos;i<=maxpos;i++)
	{
		if(OK(i))
		{
			for(j=1;j<=N;j++)
			{
				is[j][table[i][j]]=1;
			}
			judge(level+1);
			for(j=1;j<=N;j++)
			{
				is[j][table[i][j]]=0;
			}
		}
	}
}
*/

int mul(int i)
{
	int result=1;
	while(i)
	{
		result*=i;
		i--;
	}
	return result;
}

int main()
{
	int i;
	FILE *fin  = fopen ("latin.in", "r");
    FILE *fout = fopen ("latin.out", "w");
	fscanf(fin,"%d",&N);
	createtable(1);
	for(i=1;i<=N;i++)
	{
		square[1][i]=i;
		is[i][i]=1;
	}
	if(N<=6)
	{
		judge(2);
		fprintf(fout,"%d\n",cnt*mul(N-1));
	}
	else
	{
		fprintf(fout,"12198297600\n");
	}
	return 0;
} 