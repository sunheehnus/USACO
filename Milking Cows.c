/*
ID: sunheco1
LANG: C
TASK: milk2
*/
#include <stdio.h>

int s[6000],e[6000],map[6000];

void quick_sort(int s1,int e1)
{
	int i,j,mid,temp;
	if(s1<e1)
	{
		i=s1;
		j=e1;
		mid=(i+j)>>1;
		temp=map[mid];
		map[mid]=map[i];
		while(i<j)
		{
			while(i<j&&s[map[j]]>=s[temp])
				j--;
			map[i]=map[j];
			while(i<j&&s[map[i]]<=s[temp])
				i++;
			map[j]=map[i];
		}
		map[i]=temp;
		quick_sort(s1,i-1);
		quick_sort(i+1,e1);
	}
}

int main()
{
	int total,i,st,et,max,inte;
	FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");
	fscanf(fin,"%d",&total);
	for(i=0;i<total;i++)
	{
		fscanf(fin,"%d %d",s+i,e+i);
		map[i]=i;
	}
	quick_sort(0,total-1);
	st=s[map[0]];
	et=e[map[0]];
	max=et-st;
	inte=0;
	for(i=0;i<total;i++)
	{
		if(s[map[i]]>=st&&s[map[i]]<=et)
		{
			if(e[map[i]]>et)
				et=e[map[i]];
		}
		else
		{
			if(et-st>max)
				max=et-st;
			if(s[map[i]]-et>inte)
				inte=s[map[i]]-et;
			st=s[map[i]];
			et=e[map[i]];
		}
	}
	fprintf(fout,"%d %d\n",max,inte);
	return 0;
}