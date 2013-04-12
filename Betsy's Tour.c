/*
ID: sunheco1
LANG: C
TASK: betsy
*/
#include<stdio.h>

char area[10][10];

int N;
int total,visit,cnt;

void Initialize()
{
	int i;
	for(i=0;i<=N+1;i++)
	{
		area[0][i]=area[i][0]=area[N+1][i]=area[i][N+1]=1;
	}
	total=N*N;
}

int isspecial(int x,int y)
{
	return (!(x==N&&y==1))&&(area[x][y]==0)&&(area[x-1][y]+area[x][y-1]+area[x+1][y]+area[x][y+1]==3);
}

void DFS(int x,int y)
{
	int special;
	if(area[x-1][y]==1&&area[x+1][y]==1&&area[x][y-1]==0&&area[x][y+1]==0||area[x-1][y]==0&&area[x+1][y]==0&&area[x][y-1]==1&&area[x][y+1]==1)
		return;
	area[x][y]=1;
	visit++;
	if(x==N&&y==1)
	{
		if(visit==total)
		{
			cnt++;
		}
	}
	else
	{
		special=isspecial(x-1,y)+isspecial(x+1,y)+isspecial(x,y-1)+isspecial(x,y+1);
		if(special==0)
		{
			if(area[x-1][y]==0)
			{
				DFS(x-1,y);
			}
			if(area[x][y+1]==0)
			{
				DFS(x,y+1);
			}
			if(area[x+1][y]==0)
			{
				DFS(x+1,y);
			}
			if(area[x][y-1]==0)
			{
				DFS(x,y-1);
			}
		}
		else if(special==1)
		{
			if(isspecial(x-1,y))
			{
				DFS(x-1,y);
			}
			if(isspecial(x,y+1))
			{
				DFS(x,y+1);
			}
			if(isspecial(x+1,y))
			{
				DFS(x+1,y);
			}
			if(isspecial(x,y-1))
			{
				DFS(x,y-1);
			}		
		}
	}
	visit--;
	area[x][y]=0;
}

int main()
{
	FILE *fin  = fopen ("betsy.in", "r");
    FILE *fout = fopen ("betsy.out", "w");
	fscanf(fin,"%d",&N);
	Initialize();
	DFS(1,1);
	fprintf(fout,"%d\n",cnt);
	return 0;
}