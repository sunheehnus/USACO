/*
ID: sunheco1
LANG: C
TASK: nuggets
*/
#include<stdio.h>

int map[256*256];

int tar[16],flag;

void gcd(int i,int j)
{
	if(i<j)
	{
		i=i^j;
		j=i^j;
		i=i^j;
	}
	if(j==1)
		flag=1;
	if(i%j==0)
		return;
	gcd(j,i%j);
}

int main()
{
	int total,i,j,cell;
	FILE *fin  = fopen ("nuggets.in", "r");
    FILE *fout = fopen ("nuggets.out", "w");
	cell=(256<<8)-(256<<1);
	fscanf(fin,"%d",&total);
	for(i=1;i<=total;i++)
	{
		fscanf(fin,"%d",tar+i);
	}
	for(i=1;i<total;i++)
	{
		for(j=i+1;j<=total;j++)
		{
			gcd(tar[i],tar[j]);
		}
	}
	if(flag==0)
	{
		fprintf(fout,"0\n");
		return 0;
	}
	for(map[0]=1,i=0;i<=cell;i++)
	{
		if(map[i])
		{
			for(j=1;j<=total;j++)
			{
				if(i+tar[j]<=cell)
					map[i+tar[j]]=1;
			}
		}
	}
	for(i=cell;i>0;i--)
	{
		if(map[i]==0)
		{
			fprintf(fout,"%d\n",i);
			break;
		}
	}
	if(i==0)
		fprintf(fout,"0\n");
	return 0;
}