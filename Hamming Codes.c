/*
ID: sunheco1
LANG: C
TASK: hamming
*/
#include<stdio.h>

int n,b,d,max,cur,flag;

int step[128];

int Judge(int i)
{
	i=i-((i&0xAA)>>1);
	i=(i&0x33)+((i>>2)&0x33);
	i=(i+(i>>4))&0xF;
	return i>=d?0:1;
}

int agree(int i)
{
	int j;
	for(j=1;j<=cur;j++)
	{
		if(Judge(i^step[j]))
			return 0;
	}
	return 1;
}

void Find(int begin)
{
	int i;
	for(i=begin;i<=max;i++)
	{
		if(agree(i))
		{
			cur++;
			step[cur]=i;
			if(cur>=n)
			{
				flag=1;
				return;
			}
			Find(i+1);
			if(cur>=n)
			{
				flag=1;
				return;
			}
			cur--;
		}
	}
}


int main()
{
	int i;
	FILE *fin  = fopen ("hamming.in", "r");
    FILE *fout = fopen ("hamming.out", "w");
	fscanf(fin,"%d %d %d",&n,&b,&d);
	max=(1<<b)-1;
	Find(0);
	fprintf(fout,"%d",step[1]);
	for(i=2;i<=cur;i++)
	{
		fprintf(fout," %d",step[i]);
		if(i%10==0)
		{
			fprintf(fout,"\n");
			if(i+1<=cur)
				fprintf(fout,"%d",step[++i]);
		}
	}
	if((i-1)%10!=0)
		fprintf(fout,"\n");
	return 0;
}