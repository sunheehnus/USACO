/*
ID: sunheco1
LANG: C
TASK: buylow
*/
#include<stdio.h>

int total,cnt,max,Degree;

int map[5005],rank[5005];

int degree[5005][100];

int length[5005];

int judge[5005];

void add(int s,int e)
{
	int c,i,ceil,tmp;
	ceil=length[s]>length[e]?length[s]:length[e];
	for(c=0,i=1;i<=ceil;i++)
	{
		tmp=degree[s][i]+degree[e][i]+c;
		degree[s][i]=tmp%10;
		c=tmp/10;
	}
	if(c)
	{
		ceil++;
		degree[s][i]=c;
	}
	length[s]=ceil;
}

int main()
{
	int i,j,k,tmprank;
	FILE *fin  = fopen ("buylow.in", "r");
    FILE *fout = fopen ("buylow.out", "w");
	fscanf(fin,"%d",&total);
	for(i=1;i<=total;i++)
		fscanf(fin,"%d",map+i);
	rank[1]=1;
	for(i=2;i<=total;i++)
	{
		for(j=1,tmprank=1;j<i;j++)
		{
			if(map[j]>map[i]&&rank[j]>=tmprank)
				tmprank=rank[j]+1;
		}
		rank[i]=tmprank;
	}
	for(i=1,max=0;i<=total;i++)
	{
		if(rank[i]>max)
			max=rank[i];
	}
	for(i=1;i<=total;i++)
	{
		if(rank[i]==1)
		{
			degree[i][1]=1;
			length[i]=1;
		}
	}
	for(i=2;i<=total;i++)
	{
		for(j=i-1,cnt=0;j>0;j--)
		{
			if(map[j]>map[i]&&rank[j]==rank[i]-1)
			{
				for(k=1;k<=cnt;k++)
				{
					if(judge[k]==map[j])
						break;
				}
				if(k<=cnt)
					continue;
				cnt++;
				judge[cnt]=map[j];
				add(i,j);
			}
		}

	}
	for(j=total,cnt=0;j>=1;j--)
	{
		if(rank[j]==max)
		{
			for(k=1;k<=cnt;k++)
			{
				if(judge[k]==map[j])
					break;
			}
			if(k<=cnt)
				continue;
			cnt++;
			judge[cnt]=map[j];
			add(0,j);
		}
	}
	fprintf(fout,"%d ",max);
	for(i=length[0];i>0;i--)
	{
		fprintf(fout,"%d",degree[0][i]);
	}
	fprintf(fout,"\n");
	return 0;
}


