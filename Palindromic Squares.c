/*
ID: sunheco1
LANG: C
TASK: palsquare
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

int main()
{
	int base,i,j,tar;
	FILE *fin  = fopen ("palsquare.in", "r");
    FILE *fout = fopen ("palsquare.out", "w");
	fscanf(fin,"%d",&base);
	for(i=1;i<=300;i++)
	{
		if(Judge(i*i,base))
		{
			tar=i;
			for(j=0;tar;j++)
			{
				temp[j]=tar%base;
				tar/=base;
			}
			j--;
			while(j>=0)
			{
				if(temp[j]>=0&&temp[j]<=9)
					fprintf(fout,"%d",temp[j]);
				else
					fprintf(fout,"%c",temp[j]-10+'A');
				j--;
			}
			fprintf(fout," ");
			tar=i*i;
			for(j=0;tar;j++)
			{
				temp[j]=tar%base;
				tar/=base;
			}
			j--;
			while(j>=0)
			{
				if(temp[j]>=0&&temp[j]<=9)
					fprintf(fout,"%d",temp[j]);
				else
					fprintf(fout,"%c",temp[j]-10+'A');
				j--;
			}
			fprintf(fout,"\n");
		}
	}
	return 0;
}