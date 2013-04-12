/*
ID: sunheco1
LANG: C
TASK: milk4
*/
#include<stdio.h>
#include<string.h>

int buckets[256];
int cnt;
int out[256];

char quarts[20002];

int Q,total;

void quicksort(int l,int u)
{
	int i,j,mid,tmp;
	if(l<u)
	{
		i=l;
		j=u;
		mid=(l+u)>>1;
		tmp=buckets[mid];
		buckets[mid]=buckets[l];
		while(i<j)
		{
			while(i<j&&buckets[j]>=tmp)
				j--;
			buckets[i]=buckets[j];
			while(i<j&&buckets[i]<=tmp)
				i++;
			buckets[j]=buckets[j];
		}
		buckets[i]=tmp;
		quicksort(l,i-1);
		quicksort(i+1,u);
	}
}

int del(int total)
{
	int i,j;
	for(i=1,j=2;j<=total;)
	{
		if(buckets[i]==buckets[j])
		{
			j++;
		}
		else
		{
			buckets[++i]=buckets[j++];
		}
	}
	return i;
}

void deal(int now,int nlevel,int tlevel)
{
	int i,j;
	if(nlevel<=tlevel)
	{
		for(i=now;i<=total-tlevel+nlevel;i++)
		{
			for(j=0;j<=Q;j++)
			{
				if(quarts[j]>=nlevel)
					quarts[j]=0;
			}
			for(j=0;j<=Q-buckets[i];j++)
			{
				if(quarts[j])
				{
					quarts[j+buckets[i]]=nlevel;
				}
			}
			if(quarts[Q])
			{
				out[nlevel]=buckets[i];
				return;
			}
			deal(i+1,nlevel+1,tlevel);
			if(quarts[Q])
			{
				out[nlevel]=buckets[i];
				return;
			}
		}
	}
}

int findout(int sum)
{
	memset(quarts,0,sizeof(quarts));
	quarts[0]=-1;
	deal(1,1,sum);
	return quarts[Q]!=0?quarts[Q]:-1;
}

int main()
{
	int i,l,u,flag;
	FILE *fin  = fopen ("milk4.in", "r");
    FILE *fout = fopen ("milk4.out", "w");
	fscanf(fin,"%d",&Q);
	fscanf(fin,"%d",&total);
	for(i=1;i<=total;i++)
		fscanf(fin,"%d",buckets+i);
	quicksort(1,total);
	total=del(total);
	l=1;
	u=total;
	cnt=(l+u)>>1;
	while(l<=u)
	{
		flag=findout(cnt);
		if(flag==-1)
			l=cnt+1;		
		else
			u=flag-1;
		cnt=(l+u)>>1;
	}
	cnt=l;

	fprintf(fout,"%d ",l);

	for(i=1;i<l;i++)
	{
		fprintf(fout,"%d ",out[i]);
	}

	fprintf(fout,"%d\n",out[i]);
	return 0;
}