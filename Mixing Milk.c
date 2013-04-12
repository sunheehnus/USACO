/*
ID: sunheco1
LANG: C
TASK: milk
*/
#include<stdio.h>
    
int N,M,i,sum,pri[5555],tot[5555],map[5555];

void quick_sort(int s,int e)
{
	int i,j,mid,temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=s+e>>1;
		temp=map[mid];
		map[mid]=map[s];
		while(i<j)
		{
			while(i<j&&pri[map[j]]>=pri[temp])
				j--;
			map[i]=map[j];
			while(i<j&&pri[map[i]]<=pri[temp])
				i++;
			map[j]=map[i];
		}
		map[i]=temp;
		quick_sort(s,i-1);
		quick_sort(i+1,e);
	}
}

int main()
{
	FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");
	fscanf(fin,"%d %d",&N,&M);
	for(i=0;i<M;i++)
	{
		fscanf(fin,"%d %d",pri+i,tot+i);
		map[i]=i;
	}
	quick_sort(0,M-1);
	for(i=0;i<M;i++)
	{
		if(tot[map[i]] <=N)
		{
			sum+=pri[map[i]]*tot[map[i]];
			N-=tot[map[i]];
		}
		else
		{
			sum+=pri[map[i]]*N;
			break;
		}
	}
	fprintf(fout,"%d\n",sum);
	return 0;
}
