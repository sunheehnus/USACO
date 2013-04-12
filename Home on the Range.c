/*
ID: sunheco1
LANG: C
TASK: range
*/
#include<stdio.h>

char field[251][256],judge[2097152],temp[252];

int tot,tem;

void initialize(int cur)
{
	int i,j,k;
	for(i=1;i<=tot;i++)
	{
		if(field[cur][i]==0)
			continue;
		for(j=i+1;j<=tot;j++)
		{
			if(field[cur][j]==0)
				break;
			for(k=i;k<j;k++)
			{
				tem=(cur<<16)|(k<<8)|j;
				judge[tem>>3]|=1<<(tem&0x7);
			}
		}
		i=j;
	}
}

int main()
{
	int i,j,k,now,flag,cur;
	char *tar=temp;
	FILE *fin  = fopen ("range.in", "r");
    FILE *fout = fopen ("range.out", "w");
	fscanf(fin,"%d",&tot);
	for(i=1;i<=tot;i++)
	{
		fscanf(fin,"%s",tar+1);
		for(j=1;j<=tot;j++)
			field[i][j]=temp[j]-'0';
	}
	for(i=1;i<=tot;i++)
		initialize(i);
	for(i=1;i<=tot;i++)
	{
		for(j=1,now=0;j<=tot-i;j++)
		{
			for(k=1,flag=0,cur=i+1;k<=tot;k++)
			{
				tem=(k<<16)|(j<<8)|(j+i);
				if(!(judge[tem>>3]&(1<<((tem&0x7)))))
				{
					cur=i+1;
					flag=0;
					continue;
				}
				if(flag)
				{
					now++;
				}
				else if(cur==1)
				{
					flag=1;
					cur--;
					now++;
				}
				else
					cur--;
			}
		}
		if(now==0)
			break;
		fprintf(fout,"%d %d\n",i+1,now);
	}
	return 0;
}
