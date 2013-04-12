/*
ID: sunheco1
LANG: C
TASK: preface
*/
#include<stdio.h>

int sign[8];
char si[8]={'@','I','V','X','L','C','D','M',};

void add(int i,int j)
{
	switch(i)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		sign[j]+=i;
		break;
	case 8:
		sign[j]++;
	case 7:
		sign[j]++;
	case 6:
	case 4:
		sign[j]++;
	case 5:
		sign[j+1]++;
		break;
	case 9:
		sign[j+2]++;
		sign[j]++;
		break;
	}
}

void compute(int i)
{
	int temp1,temp2,temp3;
	sign[7]+=i/1000;
	temp1=(i%1000)/100;
	temp2=(i%100)/10;
	temp3=i%10;
	add(temp1,5);
	add(temp2,3);
	add(temp3,1);
}

int main()
{
	int i,tot;
	FILE *fin  = fopen ("preface.in", "r");
    FILE *fout = fopen ("preface.out", "w");
	fscanf(fin,"%d",&tot);
	for(i=1;i<=tot;i++)
		compute(i);
	for(i=1;i<=7;i++)
	{
		if(sign[i])
			fprintf(fout,"%c %d\n",si[i],sign[i]);
	}
	return 0;
}