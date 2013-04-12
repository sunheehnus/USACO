/*
ID: sunheco1
LANG: C
TASK: maze1
*/
#include<stdio.h>

struct Root{int r,c,step;};
struct Root root[16384];

int maze[222][88];

char target[111];

int now,thistime,min,W,H;

void Find(int i,int j)
{
	int hd,rr,r,c,step;
	hd=0;
	rr=1;
	root[0].r=i;
	root[0].c=j;
	root[0].step=0;
	while(1)
	{
		r=root[hd].r;
		c=root[hd].c;
		step=root[hd].step;
		hd=hd+1&16383;
		if(maze[r-1][c]<now)
		{
			if(r-2<0)
			{
				thistime=step+1;
				return;
			}
			if(maze[r-2][c]<now)
			{
				root[rr].r=r-2;
				root[rr].c=c;
				root[rr].step=step+1;
				rr=rr+1&16383;
				maze[r-2][c]=now;
			}
		}
		if(maze[r][c+1]<now)
		{
			if(c+2==W)
			{
				thistime=step+1;
				return;
			}
			if(maze[r][c+2]<now)
			{
				root[rr].r=r;
				root[rr].c=c+2;
				root[rr].step=step+1;
				rr=rr+1&16383;
				maze[r][c+2]=now;
			}
		}
		if(maze[r+1][c]<now)
		{
			if(r+2==H)
			{
				thistime=step+1;
				return;
			}
			if(maze[r+2][c]<now)
			{
				root[rr].r=r+2;
				root[rr].c=c;
				root[rr].step=step+1;
				rr=rr+1&16383;
				maze[r+2][c]=now;
			}
		}
		if(maze[r][c-1]<now)
		{
			if(c-2<0)
			{
				thistime=step+1;
				return;
			}
			if(maze[r][c-2]<now)
			{
				root[rr].r=r;
				root[rr].c=c-2;
				root[rr].step=step+1;
				rr=rr+1&16383;
				maze[r][c-2]=now;
			}
		}
	}
}

int main()
{
	int i,j;
	FILE *fin  = fopen ("maze1.in", "r");
    FILE *fout = fopen ("maze1.out", "w");
	fscanf(fin,"%d %d",&W,&H);
	W=(W<<1)+1;
	H=(H<<1)+1;
	now=1;
	for(i=0;i<H;i++)
	{
		fgets(target,111,fin);
		while(target[0]!='+'&&target[0]!='|'&&target[0]!='-'&&target[0]!=' ')
			fgets(target,111,fin);
		for(j=0;j<W;j++)
		{
			if(target[j]=='+'||target[j]=='-'||target[j]=='|')
				maze[i][j]=100000;
		}
	}
	for(i=1;i<H;i+=2)
	{
		for(j=1;j<W;j+=2,now++)
		{
			Find(i,j);
			if(thistime>min)
				min=thistime;
		}
	}
	fprintf(fout,"%d\n",min);
	return 0;
}
