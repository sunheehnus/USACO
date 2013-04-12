/*
ID: sunheco1
LANG: C
TASK: zerosum
*/
#include<stdio.h>

char step[100]={'1'};

char out[20][100];

int target,cur,tot;

int Yes()
{
	char compute[100],*tem=compute;
	int i,j,result,temp;
	for(i=0,j=0;step[i]!='\0';i++)
	{
		if(step[i]==' ')
			continue;
		compute[j]=step[i];
		j++;
	}
	compute[j]='\0';
	result=0;
	while(*tem>='1'&&*tem<='9')
	{
		result=result*10+*tem-'0';
		tem++;
	}
	if(*tem=='\0')
		return 0;
	while(*tem!='\0')
	{
		if(*tem=='+')
		{
			tem++;
			temp=0;
			while(*tem>='1'&&*tem<='9')
			{
				temp=10*temp+*tem-'0';
				tem++;
			}
			result+=temp;
		}
		else if(*tem=='-')
		{
			tem++;
			temp=0;
			while(*tem>='1'&&*tem<='9')
			{
				temp=10*temp+*tem-'0';
				tem++;
			}
			result-=temp;
		}
	}
	return !result;
}

void Find(int now)
{
	int i;
	if(now>target)
	{
		step[cur+1]='\0';
		if(Yes())
		{
			for(i=0;step[i]!='\0';i++)
				out[tot][i]=step[i];
			out[tot++][i]='\0';
		}
		return;
	}
	cur+=2;
	step[cur]=now+'0';
	step[cur-1]=' ';
	Find(now+1);
	step[cur-1]='+';
	Find(now+1);
	step[cur-1]='-';
	Find(now+1);
	cur-=2;
	return;
}

int main()
{
	int i;
	FILE *fin  = fopen ("zerosum.in", "r");
    FILE *fout = fopen ("zerosum.out", "w");
	fscanf(fin,"%d",&target);
	Find(2);
	for(i=0;i<tot;i++)
	{
		fprintf(fout,"%s\n",&out[i][0]);
	}
	return 0;
}