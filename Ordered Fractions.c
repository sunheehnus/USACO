/*
ID: sunheco1
LANG: C
TASK: frac1
*/
#include <stdio.h>

int num[222];

int tot,cur;

int function()
{
	double min=1,now;
	int i;
	for(i=2;i<=tot;i++)
	{
		if((now=(double)num[i]/i)<min)
		{
			min=now;
			cur=i;
		}
	}
	if(min==1)
		return 0;
	return 1;
}
int judge(int i,int j)
{
	int k;
	for(k=2;k<=i;k++)
	{
		if(i%k==0&&j%k==0)
			return 1;
	}
	return 0;
}
int main()
{
	int i;
	FILE *fin  = fopen ("frac1.in", "r");
    FILE *fout = fopen ("frac1.out", "w");
	fscanf(fin,"%d",&tot);
	for(i=2;i<=tot;i++)
		num[i]=1;
	fprintf(fout,"0/1\n");
	while(function())
	{
		fprintf(fout,"%d/%d\n",num[cur],cur);
		num[cur]++;
		while(judge(num[cur],cur)&&num[cur]!=cur)
			num[cur]++;
	}
	fprintf(fout,"1/1\n");
	return 0;
}