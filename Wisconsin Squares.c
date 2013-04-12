/*
ID: sunheco1
LANG: C
TASK: wissqu
*/
#include<stdio.h>

char ori[6][6],tar[6][6],output[6][6],visit[6][6];

int left[8],Devil[8],cnt,flag;

struct Cows{int i,j;}cows[6];

struct Route{int i,j,kind;}route[16];

FILE *fin,*fout;

int Judge(int i,int j,char a)
{
	if(visit[i][j]==1||(a=='D'&&ori[i][j]!='C')||tar[i-1][j-1]==a||tar[i-1][j]==a||tar[i-1][j+1]==a||tar[i][j-1]==a||tar[i][j]==a||tar[i][j+1]==a||tar[i+1][j-1]==a||tar[i+1][j]==a||tar[i+1][j+1]==a)
		return 0;
	return 1;
}

void Deal(int level)
{
	int i,j,k;
	if(level==16)
	{
		if(flag==0)
		{
			for(i=0;i<16;i++)
			{
				fprintf(fout,"%c %d %d\n",route[i].kind+'A',route[i].i,route[i].j);
			}
			flag=1;
		}
		cnt++;
		return;
	}
	for(k=0;k<5;k++)
	{
		if(left[k]==0)
			continue;
		for(i=1;i<=4;i++)
		{
			for(j=1;j<=4;j++)
			{
				if(left[k]==3&&Judge(i,j,'A'+k))
				{
					cows[k].i=i;
					cows[k].j=j;
				}
				if(left[k]!=3&&ori[i][j]!=ori[cows[k].i][cows[k].j])
					continue;
				if(Judge(i,j,'A'+k))
				{
					left[k]--;
					visit[i][j]=1;
					tar[i][j]='A'+k;
					route[level].i=i;
					route[level].j=j;
					route[level].kind=k;
					Deal(level+1);
					tar[i][j]=ori[i][j];
					visit[i][j]=0;
					left[k]++;
				}
			}
		}
	}
}
int main()
{
	int i,j;
	fin  = fopen ("wissqu.in", "r");
    fout = fopen ("wissqu.out", "w");
	for(i=1;i<=4;i++)
		fscanf(fin,"%s",&ori[i][1]);
	left[0]=left[1]=left[2]=left[3]=left[4]=3;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			tar[i][j]=ori[i][j];
		}
	}
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			if(Judge(i,j,'D'))
			{
				visit[i][j]=1;
				tar[i][j]='D';
				route[0].i=i;
				route[0].j=j;
				route[0].kind=3;
				Deal(1);
				tar[i][j]=ori[i][j];
				visit[i][j]=0;
			}
		}
	}
	fprintf(fout,"%d\n",cnt);
	return 0;
}
