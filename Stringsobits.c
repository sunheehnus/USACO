/*
ID: sunheco1
LANG: C
TASK: kimbits
*/	
#include<stdio.h>
int result[33];
unsigned int CC(int j,int i)
{
	unsigned int k;
	int visit[33],temp,l;
	if(i>=j>>1)
		i=j-i;
	temp=i;
	for(l=2;l<=i;l++)
		visit[l]=0;
	for(k=1;i>0;i--,j--)
	{
		k*=j;
		for(l=2;l<=temp;l++)
		{
			if(visit[l]==0&&k%l==0)
			{
				k/=l;
				visit[l]=1;
			}
		}
	}
	for(l=2;l<=temp;l++)
	{
		if(visit[l]==0&&k%l==0)
		{
			k/=l;
			visit[l]=1;
		}
	}
	return k;
}
int main()
{
	unsigned int N,L,I,i,j,k,tot;
	unsigned int total[33][33];
	FILE *fin  = fopen ("kimbits.in", "r");
    FILE *fout = fopen ("kimbits.out", "w");
	fscanf(fin,"%d %d %u",&N,&L,&I);
	if(I==1)
	{
		while(N)
		{
			fprintf(fout,"%d",0);
			N--;
		}
		fprintf(fout,"\n");
		return 0;
	}
	for(j=0;j<=32;j++)
	{
		total[j][0]=1;
	}
	for(i=1;i<=32;i++)
	{
		for(j=1;j<=i;j++)
		{
			total[i][j]=CC(i,j);
		}
	}
	for(i=1;;i++)
	{
		for(k=0,tot=0;k<=L&&k<i;k++)
		{
			tot+=total[i-1][k];
		}
		for(k=0;k<L&&k<i;k++)
		{
			tot+=total[i-1][k];
		}
		if(tot>=I)
			break;
	}
	for(k=0,tot=0;k<=L&&k<i;k++)
	{
		tot+=total[i-1][k];
	}
	result[i]=1;
	L--;
	I-=tot;
	I--;
	while(I)
	{
		i--;
		for(k=0,tot=0;k<=L&&k<i;k++)
		{
			tot+=total[i-1][k];
		}
		if(tot>I)
			continue;
		I-=tot;
		result[i]=1;
		L--;
	}
	while(N)
	{
		fprintf(fout,"%d",result[N]);
		N--;
	}
	fprintf(fout,"\n");
	return 0;
}
