/*
ID: sunheco1
LANG: C
TASK: rectbarn
*/
#include<stdio.h>

char space[3004][3004];

int h[2][3004],l[2][3004],r[2][3004],ltmp[2][3004],rtmp[2][3004];

int R,C,P,max;

void Initialize()
{
	int i,j,tmp;
	for(j=1;j<=C;j++)
	{
		if(space[1][j]==1)
		{
			h[1][j]=0;
			l[1][j]=r[1][j]=3001;
		}
		else
		{
			h[1][j]=1;
			for(i=j,tmp=0;i>0&&space[1][i]==0;i--,tmp++);
			ltmp[1][j]=l[1][j]=tmp;
			for(i=j,tmp=0;i<=C&&space[1][i]==0;i++,tmp++);
			rtmp[1][j]=r[1][j]=tmp;
			max=max<h[1][j]?h[1][j]:max;
			max=max<l[1][j]?l[1][j]:max;
			max=max<r[1][j]?r[1][j]:max;
		}
	}
}

void find(int row,int col)
{
	if(space[row][col]==0)
	{
		if(h[row&1][col]*(l[row&1][col]+r[row&1][col]-1)>max)
			max=h[row&1][col]*(l[row&1][col]+r[row&1][col]-1);
	}
}
void fill(int row)
{
	int i,tmp;
	for(i=1;i<=C;i++)
	{
		if(space[row][i]==1)
		{
			h[row&1][i]=0;
			l[row&1][i]=r[row&1][i]=3001;
		}
		else
		{
			h[row&1][i]=h[(row+1)&1][i]+1;
		}
	}
	for(i=1;i<=C;i++)
	{
		if(space[row][i]==0)
		{
			tmp=ltmp[row&1][i]=space[row][i-1]==1?1:ltmp[row&1][i-1]+1;
			l[row&1][i]=l[(row+1)&1][i]<tmp?l[(row+1)&1][i]:tmp;
		}
	}
	for(i=C;i>=1;i--)
	{
		if(space[row][i]==0)
		{
			tmp=rtmp[row&1][i]=space[row][i+1]==1?1:rtmp[row&1][i+1]+1;
			r[row&1][i]=r[(row+1)&1][i]<tmp?r[(row+1)&1][i]:tmp;
		}
	}
}
int main()
{
	int i,j,row,col;
    FILE *fin  = fopen ("rectbarn.in", "r");
    FILE *fout = fopen ("rectbarn.out", "w");
	fscanf(fin,"%d %d %d",&R,&C,&P);
	for(i=1;i<=P;i++)
	{
		fscanf(fin,"%d %d",&row,&col);
		space[row][col]=1;
	}
	Initialize();
	for(i=2;i<=R;i++)
	{
		fill(i);
		for(j=1;j<=C;j++)
		{
			find(i,j);
		}
	}
	fprintf(fout,"%d\n",max);
	return 0;
}