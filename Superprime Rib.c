/*
ID: sunheco1
LANG: C
TASK: sprime
*/
#include<stdio.h>
int now,num,total;
int map[40001],pri[40001],out[100],tot;
void Initial()
{	int i,j;
	for(i=2;i<=40000;i++)
	{
		if(map[i])
			continue;
		for(j=2*i;j<=40000;j+=i)
			map[j]=1;
	}
	for(i=2,total=1;i<=40000;i++)
	{
		if(!map[i])
			pri[total++]=i;
	}
	total--;
}
int Is(int i)
{
	int j=i>>1,k;
	for(k=1;k<=total&&pri[k]<=j;k++)
	{
		if(!(i%pri[k]))
			return 0;
	}

	return 1;
}
void find(int cur)
{
	int i;
	if(cur==1)
	{
		for(i=2;i<=9;i++)
		{
			num=i;
			if(!Is(i))
				continue;
			num*=10;
			find(cur+1);
			num/=10;
		}
	}
	else
	{
		if(cur>now)
		{
			out[++tot]=num/10;
		}
		else
		{
			for(i=1;i<=9;i++)
			{
				if(!Is(i+num))
					continue;
				num+=i;
				num*=10;
				find(cur+1);
				num/=10;
				num-=i;
			}
		}
	}
}
int main()
{
	int i;
	FILE *fin  = fopen ("sprime.in", "r");
    FILE *fout = fopen ("sprime.out", "w");
	fscanf(fin,"%d",&now);
	Initial();
	find(1);
	for(i=1;i<=tot;i++)
		fprintf(fout,"%d\n",out[i]);
	return 0;
}