/*
ID: sunheco1
LANG: C
TASK: ariprog
*/
#include <stdio.h>

int n,m,Is[150000],exist[70000],yep,st;

int OK(int a,int b,int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		a+=b;
		if(!Is[a])
			return 0;
	}
	yep=1;
	return 1;
}

int main()
{
	int i,j,now,cur,max;
	FILE *fin  = fopen ("ariprog.in", "r");
    FILE *fout = fopen ("ariprog.out", "w");
	fscanf(fin,"%d %d",&n,&m);
	for(i=0;i<=m;i++)
		exist[i]=i*i;
	for(i=0;i<=m;i++)
	{
		for(j=i;j<=m;j++)
			Is[exist[i]+exist[j]]=1;
	}
	max=m*m<<1;
	for(i=0,cur=1;i<=max;i++)
	{
		if(Is[i])
			exist[cur++]=i;
	}
	cur--;
	for(st=1;(now=i*(n-1))<=max;st++)
	{
		for(j=1;now+exist[j]<=max;j++)
		{
			if(OK(exist[j],i,n))
				break;
		}
		if(now+exist[j]<=max)
			break;
	}
	for(i=st;(now=i*(n-1))<=max;i+=st)
	{
		for(j=1;now+exist[j]<=max;j++)
		{
			if(OK(exist[j],i,n))
				fprintf(fout,"%d %d\n",exist[j],i);
		}
	}
	if(!yep)
		fprintf(fout,"NONE\n");
	return 0;
}