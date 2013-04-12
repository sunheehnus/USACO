/*
ID: sunheco1
LANG: C
TASK: cowxor
*/
#include<stdio.h>

int cowxor[100002];
int queue[100002],qp;
char map[2<<22];

int flag;

void Deal(int i)
{
	int j,now=1;
	for(j=20;j>=0;j--)
	{
		if(((cowxor[i]>>j)&1)==1)
		{
			now<<=1;
			map[now]=1;
		}
		else
		{
			now=(now<<1)+1;
			map[now]=1;
		}
	}
}

int findout(int i)
{
	int target,truth,j,now=1;
	target=~(((-1)<<21)|cowxor[i]);
	truth=0;
	for(j=20;j>=0;j--)
	{
		if(((target>>j)&1)==1)
		{
			if(map[now<<1]==1)
			{
				truth<<=1;
				truth|=1;
				now<<=1;
			}
			else
			{
				truth<<=1;
				now=(now<<1)+1;
			}
		}
		else
		{
			if(map[(now<<1)+1]==1)
			{
				truth<<=1;
				now=(now<<1)+1;
			}
			else
			{
				truth<<=1;
				truth|=1;
				now<<=1;
			}
		}
	}
	return cowxor[i]^truth;
}

int main()
{
	int i,j,s,e,N,max,tmp;
	FILE *fin  = fopen ("cowxor.in", "r");
    FILE *fout = fopen ("cowxor.out", "w");
	fscanf(fin,"%d",&N);
	for(i=1;i<=N;i++)
	{
		fscanf(fin,"%d",cowxor+i);
		cowxor[i]^=cowxor[i-1];
		Deal(i);
	}
	max=-1;	
	for(i=0;i<=N;i++)
	{
		tmp=findout(i);
		if(tmp>max)
		{
			flag=0;
			qp=0;
			queue[++qp]=i;
			max=tmp;
		}
		else if(tmp==max)
		{
			queue[++qp]=i;
		}
	}
	for(i=2;i<=qp;i++)
	{
		for(j=i-1;j>0;j--)
		{
			if(((cowxor[queue[j]])^(cowxor[queue[i]]))==max)
			{
				fprintf(fout,"%d %d %d\n",max,queue[j]+1,queue[i]);
				return 0;
			}
		}
	}
	return 0;
}
