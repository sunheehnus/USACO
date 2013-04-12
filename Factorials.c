/*
ID: sunheco1
LANG: C
TASK: fact4
*/
#include<stdio.h>
#include<string.h>

char result[16888];
char base[4][16888];
char *tar[4];

int len;

void compute(int MUL)
{
	int i,j,c,mul,now;
	for(i=0;i<4;i++,MUL/=10)
	{
		memset(tar[i],0,len);
		if((mul=MUL%10)==0)
			continue;
		for(j=1,c=0;j<=len;j++)
		{
			now=result[j]*mul+c;
			c=now/10;
			tar[i][j]=now%10;
		}
		tar[i][j]=c;
	}
	for(j=1,len+=5,c=0;j<=len;j++)
	{
		now=base[0][j]+base[1][j]+base[2][j]+base[3][j]+c;
		result[j]=now%10;
		c=now/10;
	}
	while(result[len]==0)
		len--;
}

int main()
{
	int i,total;
	FILE *fin  = fopen ("fact4.in", "r");
    FILE *fout = fopen ("fact4.out", "w");
	for(i=0;i<4;i++)
		tar[i]=&base[i][i];	
	result[1]=1;
	len=1;
	fscanf(fin,"%d",&total);
	for(i=2;i<=total;i++)
	{
		compute(i);
	}
	for(i=1;i<=len;i++)
	{
		if(result[i]!=0)
		{
			total=result[i];
			break;
		}
	}
	fprintf(fout,"%d\n",total);
	return 0;
}