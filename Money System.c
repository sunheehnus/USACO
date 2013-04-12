/*
ID: sunheco1
LANG: C
TASK: money
*/
#include<stdio.h>

long long money[33][11111];

int tar[26];

int N,V;

void quicksort(int s,int e)
{
	int i,j,mid,temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(i+j)>>1;
		temp=tar[mid];
		tar[mid]=tar[s];
		while(i<j)
		{
			while(i<j&&tar[j]>=temp)
				j--;
			tar[i]=tar[j];
			while(i<j&&tar[i]<=temp)
				i++;
			tar[j]=tar[i];
		}
		tar[i]=temp;
		quicksort(s,i-1);
		quicksort(i+1,e);
	}
}


int main()
{
	int i,j,k,temp;
	long long result=0;
	FILE *fin  = fopen ("money.in", "r");
    FILE *fout = fopen ("money.out", "w");
	fscanf(fin,"%d %d",&V,&N);
	for(j=1;j<=V;j++)
	{
		fscanf(fin,"%d",tar+j);
	}
	quicksort(1,V);
	for(j=1;j<=V;j++)
	{
		money[j][tar[j]]=1;
	}
	for(i=tar[1]+1;i<=N;i++)
	{
		for(j=1;tar[j]<=i>>1;j++)
		{
			temp=i-tar[j];
			for(k=j;k<=V;k++)
				money[j][i]+=money[k][temp];
		}
	}
	for(i=1;i<=V;i++)
		result+=money[i][N];
	fprintf(fout,"%lld\n",result);
	return 0;
}
//3 10 1 2 5