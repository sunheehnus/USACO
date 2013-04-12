/*
ID: sunheco1
LANG: C
TASK: runround
*/
#include<stdio.h>

int num[55],step[55],exist[10],out[55]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};

int tar,flag,tot,EXT;

void Initialize(int i)
{
	int j;
	while(i)
	{
		num[tot++]=i%10;
		i/=10;
	}
	tot--;
	for(i=0,j=tot;i<j;i++,j--)
	{
		num[i]^=num[j];
		num[j]^=num[i];
		num[i]^=num[j];
	}
}

int JudgeO(int target,int now)
{
	int i;
	for(i=0;i<=tot;i++)
	{
		if(out[i]==target)
			return 0;
	}
	while(out[target]!=-1&&out[target]!=now)
		target=out[target];
	target=out[target];
	return target==-1?1:0;
}

int JudgeF(int target,int now)
{
	int i;
	for(i=0;i<tot;i++)
	{
		if(out[i]==target)
			return 0;
	}
	return 1;
}

void Find(int now)
{
	int i,target;
	i=flag?num[now]:1;
	if(i==0)
	{
		flag=0;
		i++;
	}
	if(now==tot)
	{
		if(flag)
		{
			flag=0;
			i++;
		}
		for(;i<=9;i++,flag=0)
		{
			if(exist[i])
				continue;
			target=(i+now)%(tot+1);
			if(target!=now&&JudgeF(target,now))
			{
				step[now]=i;
				EXT=1;
				return;
			}
		}
	}
	else
	{
		for(;i<=9&&!EXT;i++,flag=0)
		{
			if(exist[i])
				continue;
			target=(i+now)%(tot+1);
			if(target!=now&&JudgeO(target,now))
			{
				exist[i]=1;
				step[now]=i;
				out[now]=target;
				Find(now+1);
				out[now]=-1;
				exist[i]=0;
			}
		}
	}
}

int main()
{
	FILE *fin  = fopen ("runround.in", "r");
    FILE *fout = fopen ("runround.out", "w");
	fscanf(fin,"%d",&tar);
	Initialize(tar);
	flag=1;
	Find(0);
	if(!EXT)
	{
	/*	while(tar)
		{
			fprintf(fout,"1");
			tar/=10;
		}
		fprintf(fout,"1\n");*/
		flag=0;
		tot++;
		Find(0);
	}
//	else
//	{
		for(flag=0;flag<=tot;flag++)
			fprintf(fout,"%d",step[flag]);
		fprintf(fout,"\n");
//	}
	return 0;
}