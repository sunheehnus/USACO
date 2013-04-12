/*
ID: sunheco1
LANG: C
TASK: job
*/
#include<stdio.h>
#include<string.h>
int N,MA,MB,NOW;

int PA[32],PB[32],TS[1024],TE[1024],TA[32],TB[32];

void quicksort(int *a,int s,int e)
{
	int i,j,mid,temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(s+e)>>1;
		temp=a[mid];
		a[mid]=a[i];
		while(i<j)
		{
			while(i<j&&temp<=a[j])
				j--;
			a[i]=a[j];
			while(i<j&&temp>=a[i])
				i++;
			a[j]=a[i];
		}
		a[i]=temp;
		quicksort(a,s,i-1);
		quicksort(a,i+1,e);
	}
}

void FuncA()
{
	int i,min;
	for(i=1,min=0x7fffffff;i<=MA;i++)
	{
		if(TA[i]+PA[i]<min)
		{
			min=TA[i]+PA[i];
			NOW=i;
		}
	}
	TA[NOW]+=PA[NOW];
}

void FuncB()
{
	int i,min;
	for(i=1,min=0x7fffffff;i<=MB;i++)
	{
		if(TB[i]+PB[i]<min)
		{
			min=TB[i]+PB[i];
			NOW=i;
		}
	}
	TB[NOW]+=PB[NOW];
}

int main()
{
	int i,j,max;
	FILE *fin  = fopen ("job.in", "r");
    FILE *fout = fopen ("job.out", "w");
	fscanf(fin,"%d %d %d",&N,&MA,&MB);
	for(i=1;i<=MA;i++)
		fscanf(fin,"%d",PA+i);
	for(i=1;i<=MB;i++)
		fscanf(fin,"%d",PB+i);
	quicksort(PA,1,MA);
	quicksort(PB,1,MB);
	for(i=1;i<=N;i++)
	{
		FuncA();
		TS[i]=TA[NOW];
	}
	fprintf(fout,"%d ",TS[N]);
	for(i=1;i<=N;i++)
	{
		FuncB();
		TE[i]=TB[NOW];
	}
	for(i=1,max=0;i<=N;i++)
	{
		if(TS[i]+TE[N-i+1]>max)
			max=TS[i]+TE[N-i+1];
	}
	fprintf(fout,"%d\n",max);
	return 0;
}