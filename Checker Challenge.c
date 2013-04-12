/*
ID: sunheco1
LANG: C
TASK: checker 
*/
#include<stdio.h>
int target1,target2,target3,step[100],map[5][14];
int N,current,bg,b1,b2,flag,fh;

void find(int now)
{
	int i,s1,s2,s3,tem;
	if(flag)
		return;
	if(!bg&&now==2&&step[1]==b1)
	{
		fh=current;
		if(current>2)
		{
			flag=1;
			return;
		}
	}
	if(bg&&now==3&&step[1]==b1&&step[2]>=b2)
	{
		fh=current;
		flag=1;
		return;
	}
	if(now>N)
	{
		current++;
		if(current>3)
			return;
		for(i=1;i<=N;i++)
			map[current][i]=step[i];
	}
	for(i=1;i<=N;i++)
	{
		if(i>now)
		{
			s1=(1<<(i-now+16));
		}
		else
		{
			s1=1<<(now-i);
		}
		if((tem=N-i+1)>now)
		{
			s2=1<<((tem-now+16));
		}
		else
		{
			s2=1<<(now-tem);
		}
		s3=1<<(i-1);
		if((target1&s1)||(target2&s2)||(target3&s3))
			continue;
		target1|=s1;
		target2|=s2;
		target3|=s3;
		step[now]=i;
		find(now+1);
		target1^=s1;
		target2^=s2;
		target3^=s3;
	}
}
int main()
{
	int i,j;
	FILE *fin  = fopen ("checker.in", "r");
    FILE *fout = fopen ("checker.out", "w");
	fscanf(fin,"%d",&N);
	bg=N&1;
	b1=(N>>1)+1;
	b2=(N>>1)+2;
	find(1);
	for(i=1;i<=3;i++)
	{
		for(j=1;j<N;j++)
			fprintf(fout,"%d ",map[i][j]);
		fprintf(fout,"%d\n",map[i][j]);
	}
	fprintf(fout,"%d\n",fh+fh);
	return 0;
}
