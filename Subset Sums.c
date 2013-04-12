/*
ID: sunheco1
LANG: C
TASK: subset
*/
#include<stdio.h>

int max;

int map[1000][1000];
int flag[1000][1000];

int Find(int small,int big)
{
	int temp,i;
	if(small>=big)
		return 0;
	if(map[small][big])
		return map[small][big];	
	if(flag[small][big])
		return 0;
	temp=big<=max?1:0;
	if(big>=(small<<1)+3)
	{
		for(i=small+1;i<=big;i++)
			temp+=Find(i,big-i);
	}
	map[small][big]=temp;
	flag[small][big]=1;
	return temp;
}

int main()
{
	int i,tem,temp;
	FILE *fin  = fopen ("subset.in", "r");
    FILE *fout = fopen ("subset.out", "w");
	fscanf(fin,"%d",&max);
	temp=Find(1,tem=(1+max)*max>>2);
	if((1+max)*max>>1&1)
		fprintf(fout,"0\n");
	else
		fprintf(fout,"%d\n",temp);
	return 0;
}