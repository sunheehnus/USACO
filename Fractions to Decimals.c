/*
ID: sunheco1
LANG: C
TASK: fracdec
*/
#include<stdio.h>

int MJ,left,mod,recycle,total;

char out[222222];

int Judge[111111];

int main()
{
	int i,j,cur;
	FILE *fin  = fopen ("fracdec.in", "r");
    FILE *fout = fopen ("fracdec.out", "w");
	fscanf(fin,"%d %d",&left,&mod);
	sprintf(out,"%d.",left/mod);
	MJ=left%mod;
	cur=0;
	while(out[cur]!='\0')
		cur++;
	if(MJ==0)
	{
		sprintf(out,"%s0",out);
	}
	else
	{
		left=MJ;
		while(left!=0&&!Judge[left])
		{
			Judge[left]=1;
			left=(left*10)%mod;
		}
		if(left==0)
		{
			left=MJ;
			while(left!=0)
			{
				out[cur++]=left*10/mod+'0';
				left=(left*10)%mod;
			}
		}
		else
		{
			recycle=MJ;
			while(recycle!=left)
			{
				out[cur++]=recycle*10/mod+'0';
				recycle=(recycle*10)%mod;
			}
			out[cur++]='(';
			out[cur++]=recycle*10/mod+'0';
			recycle=(recycle*10)%mod;
			while(recycle!=left)
			{
				out[cur++]=recycle*10/mod+'0';
				recycle=(recycle*10)%mod;
			}
			out[cur++]=')';
		}
		out[cur]='\0';
	}
	for(i=0;;i+=76)
	{
		for(j=0;j<=75&&out[i+j]!='\0';j++)
			fprintf(fout,"%c",out[i+j]);
		if(j==76)
			fprintf(fout,"\n");
		if(j!=76&&out[i+j]=='\0')
			break;
	}
	if(j!=76)
		fprintf(fout,"\n");
	return 0;
}