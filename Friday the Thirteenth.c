/*
ID: sunheco1
LANG: C
TASK: friday
*/
#include<stdio.h>
int map[12]={31,28,31,30,31,30,31,31,30,31,30,31,};
int Is[7],total;

int leap(int month)
{
	if(month%4)
		return 0;
	if(!(month%100)&&month%400)
		return 0;
	return 1;
}

int main()
{
	int n,i,j;
	FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
	fscanf(fin,"%d",&n);
	n+=1900;
	for(j=1900;j<n;j++)
	{
		for(i=0;i<12;i++)
		{
			Is[(total+13)%7]++;
			total+=map[i];
			if(i==1&&leap(j))
				total++;
		}
	}
	fprintf(fout,"%d ",Is[6]);
	fprintf(fout,"%d ",Is[0]);
	fprintf(fout,"%d ",Is[1]);
	fprintf(fout,"%d ",Is[2]);
	fprintf(fout,"%d ",Is[3]);
	fprintf(fout,"%d ",Is[4]);
	fprintf(fout,"%d\n",Is[5]);
	return 0;
}