/*
ID: sunheco1
LANG: C
TASK: rockers
*/
#include<stdio.h>

int n,t,m,max;

int tar[22];

int is[22];

void compute()
{
	int i,j,k,cur,leave;
	for(i=1,k=1,cur=0;i<=m;i++)
	{
		leave=t;
		for(j=k;j<=n;j++)
		{
			if(is[j]&&leave>=tar[j])
			{
				leave-=tar[j];
				cur++;
			}
			else if(is[j]&&leave<tar[j])
			{
				k=j;
				break;
			}
		}
		if(j>n)
			break;
	}
	if(cur>max)
		max=cur;
}


void find(int now)
{
	if(now>n)
	{
		compute();
		return;
	}
	else
	{
		is[now]=1;
		find(now+1);
		is[now]=0;
		find(now+1);
	}
}

int main()
{
	int i;
	FILE *fin  = fopen ("rockers.in", "r");
    FILE *fout = fopen ("rockers.out", "w");
	fscanf(fin,"%d %d %d",&n,&t,&m);
	for(i=1;i<=n;i++)
		fscanf(fin,"%d",tar+i);
	find(1);
	fprintf(fout,"%d\n",max);
	return 0;
}