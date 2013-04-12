/*
ID: sunheco1
LANG: C
TASK: dualpal
*/

#include<stdio.h>

int temp[50];

int Judge(int tar,int base)
{
	int i,j;
	for(i=0;tar;i++)
	{
		temp[i]=tar%base;
		tar/=base;
	}
	i--;
	for(j=0;j<i;j++,i--)
	{
		if(temp[i]!=temp[j])
			return 0;
	}
	return 1;
}

int Is(int tar)
{
	int i,flag=0;
	for(i=2;i<11;i++)
	{
		if(tar%i==0)
			continue;
		flag+=Judge(tar,i);
		if(flag>=2)
			return 1;
	}
	return 0;
}


int main()
{
	int N,s,i;
	FILE *fin  = fopen ("dualpal.in", "r");
    FILE *fout = fopen ("dualpal.out", "w");
	fscanf(fin,"%d",&N);
	fscanf(fin,"%d",&s);
	for(s++,i=N;i>0;s++)
	{
		if(Is(s))
		{
			fprintf(fout,"%d\n",s);
			i--;
		}
	}
	return 0;
}