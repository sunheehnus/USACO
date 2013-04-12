/*
ID: sunheco1
LANG: C
TASK: crypt1
*/
#include<stdio.h>

int total,N,num[100],tar[100];

int find(int i,int tt)
{
	int ta,j;
	if(tt)
	{
		if(i/10000!=0||i/1000==0)
			return 0;
	}
	else
	{
		if(i/1000!=0||i/100==0)
			return 0;
	}
	while(i)
	{
		ta=i%10;
		for(j=0;j<N;j++)
		{
			if(ta==tar[j])
				break;
		}
		if(j==N)
			return 0;
		i/=10;
	}
	return 1;
}
void compute()
{
	int a1,a2,a3,m1,m2,m3;
	a1=num[0]*100+num[1]*10+num[2];
	a2=num[3]*10;
	a3=num[4];
	m1=a1*a2;
	m2=a1*a3;
	m3=m1+m2;
	if(!find(m1/10,0))
		return;
	if(!find(m2,0))
		return;
	if(!find(m3,1))
		return;
	total++;
}
void combine(int now)
{
	int i;
	for(i=0;i<N;i++)
	{
		num[now]=tar[i];
		if(now<4)
			combine(now+1);
		else
			compute();
	}
}
int main()
{
	int i;
	FILE *fin  = fopen ("crypt1.in", "r");
    FILE *fout = fopen ("crypt1.out", "w");
	fscanf(fin,"%d",&N);
	for(i=0;i<N;i++)
		fscanf(fin,"%d",tar+i);
	combine(0);
	fprintf(fout,"%d\n",total);
	return 0;
}