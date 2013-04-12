/*
ID: sunheco1
LANG: C
TASK: ttwo
*/
#include<stdio.h>

int Is[16][11][11][11][11],map[11][11];

int fr,fc,cr,cc,cur,tot;

int Deal()
{
	int i,j;
	if(Is[cur][fr][fc][cr][cc])
		return 0;
	Is[cur][fr][fc][cr][cc]=1;
	i=cur>>2;
	j=cur&3;
	switch(j)
	{
		case 0:
			if(cr==1||map[cr-1][cc])
			{
				j=(j+1&0x3);
			}
			else
			{
				cr--;
			}
			break;
		case 1:
			if(cc==10||map[cr][cc+1])
			{
				j=(j+1&0x3);
			}
			else
			{
				cc++;
			}
			break;
		case 2:
			if(cr==10||map[cr+1][cc])
			{
				j=(j+1&0x3);
			}
			else
			{
				cr++;
			}
			break;
		case 3:
			if(cc==1||map[cr][cc-1])
			{
				j=(j+1&0x3);
			}
			else
			{
				cc--;
			}
			break;
	}
	switch(i)
	{
		case 0:
			if(fr==1||map[fr-1][fc])
			{
				i=(i+1&0x3);
			}
			else
			{
				fr--;
			}
			break;
		case 1:
			if(fc==10||map[fr][fc+1])
			{
				i=(i+1&0x3);
			}
			else
			{
				fc++;
			}
			break;
		case 2:
			if(fr==10||map[fr+1][fc])
			{
				i=(i+1&0x3);
			}
			else
			{
				fr++;
			}
			break;
		case 3:
			if(fc==1||map[fr][fc-1])
			{
				i=(i+1&0x3);
			}
			else
			{
				fc--;
			}
			break;
	}
	cur=i<<2|j;
	return 1;
}

int main()
{
	int i,j,flag=0;
	char tar[11];
	FILE *fin  = fopen ("ttwo.in", "r");
    FILE *fout = fopen ("ttwo.out", "w");
	for(i=1;i<=10;i++)
	{
		fscanf(fin,"%s",tar);
		for(j=0;j<10;j++)
		{
			if(tar[j]=='.')
				map[i][j+1]=0;
			else if(tar[j]=='*')
				map[i][j+1]=1;
			else if(tar[j]=='F')
			{
				fr=i;
				fc=j+1;
			} 
			else if(tar[j]=='C')
			{
				cr=i;
				cc=j+1;
			}
		}
	}
	while(Deal())
	{
		tot++;
		if(fr==cr&&fc==cc)
		{
			fprintf(fout,"%d\n",tot);
			flag=1;
			break;
		}
	}
	if(flag!=1)
		fprintf(fout,"0\n");
	return 0;
}