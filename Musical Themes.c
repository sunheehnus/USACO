/*
ID: sunheco1
LANG: C
TASK: theme
*/
#include<stdio.h>

int melody[5001];

int total;

int find(int lenth)
{
	int i,j,k,flag,l1,l2;
	for(i=1,l1=total-(lenth<<1)+1;i<=l1;i++)
	{
		for(j=i+lenth,l2=total-lenth+1;j<=l2;j++)
		{
			for(k=1,flag=1;k<lenth;k++)
			{
				if(melody[i+k]-melody[i]!=melody[j+k]-melody[j])
				{
					flag=0;
					break;
				}
			}
			if(flag)
				return 1;
		}
	}
	return 0;
}

int main()
{
	int i,left,right,mid;
	FILE *fin  = fopen ("theme.in", "r");
    FILE *fout = fopen ("theme.out", "w");
	fscanf(fin,"%d",&total);
	for(i=1;i<=total;i++)
		fscanf(fin,"%d",melody+i);
	right=total>>1;
	left=5;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(find(mid))
			left=mid+1;
		else
			right=mid-1;
	}
	if(right>=5)
		fprintf(fout,"%d\n",right);
	else
		fprintf(fout,"0\n");
	return 0;
}