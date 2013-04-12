/*
ID: sunheco1
LANG: C
TASK: sort3
*/
#include<stdio.h>

int tot,temp12,temp13,temp21,temp23,temp31,temp32,mov1,mov2,mov3;

int tar[2000],sep[10];

int main()
{
	int i;
	FILE *fin  = fopen ("sort3.in", "r");
    FILE *fout = fopen ("sort3.out", "w");
	fscanf(fin,"%d",&tot);
	for(i=1;i<=tot;i++)
	{
		fscanf(fin,"%d",tar+i);
		sep[tar[i]]++;
	}
	for(i=1;i<=sep[1];i++)
	{
		if(tar[i]==2)
			temp12++;
		if(tar[i]==3)
			temp13++;
	}
	for(;i<=sep[1]+sep[2];i++)
	{
		if(tar[i]==1)
			temp21++;
		if(tar[i]==3)
			temp23++;
	}
	for(;i<=tot;i++)
	{
		if(tar[i]==1)
			temp31++;
		if(tar[i]==2)
			temp32++;
	}
	mov1=temp12>temp21?temp21:temp12;
	mov2=temp13>temp31?temp31:temp13;
	mov3=temp23>temp32?temp32:temp23;
	fprintf(fout,"%d\n",mov1+mov2+mov3+((temp12+temp13+temp21+temp23+temp31+temp32-((mov1+mov2+mov3)<<1))<<1)/3);
	return 0;
}
