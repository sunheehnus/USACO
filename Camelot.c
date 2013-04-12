/*
ID: sunheco1
LANG: C
TASK: camelot
*/
#include<stdio.h>
#include<string.h>
struct Root{int visit,step,min;}root[33][33];

int min[33][33],r[9999],c[9999];

int kingmove,rt,ct,cstep,step;

struct KNIGHT{int row,col;}knight[9999];

char R[22];

int C,col,row;

void find(int nr,int nc)
{
	int s=0,e=0,r1,c1,tstep,tmin;
	memset(root,0,sizeof(root));
	root[nr][nc].min=min[nr][nc];
	root[nr][nc].visit=1;
	root[nr][nc].step=0;
	r[s]=nr;
	c[s]=nc;
	while(s<=e)
	{
		r1=r[s];
		c1=c[s];
		s++;
		tstep=root[r1][c1].step;
		tmin=root[r1][c1].min;
		if(r1<rt&&c1>2&&root[r1+1][c1-2].visit==0)
		{
			root[r1+1][c1-2].visit=1;
			root[r1+1][c1-2].step=tstep+1;
			root[r1+1][c1-2].min=tmin<min[r1+1][c1-2]?tmin:min[r1+1][c1-2];
			e++;
			r[e]=r1+1;
			c[e]=c1-2;
		}
		else if(r1<rt&&c1>2&&root[r1+1][c1-2].step==tstep+1&&root[r1+1][c1-2].min>tmin)
			root[r1+1][c1-2].min=tmin;
		if(r1<rt-1&&c1>1&&root[r1+2][c1-1].visit==0)
		{
			root[r1+2][c1-1].visit=1;
			root[r1+2][c1-1].step=tstep+1;
			root[r1+2][c1-1].min=tmin<min[r1+2][c1-1]?tmin:min[r1+2][c1-1];
			e++;
			r[e]=r1+2;
			c[e]=c1-1;
		}
		else if(r1<rt-1&&c1>1&&root[r1+2][c1-1].step==tstep+1&&root[r1+2][c1-1].min>tmin)
			root[r1+2][c1-1].min=tmin;
		if(r1<rt-1&&c1<ct&&root[r1+2][c1+1].visit==0)
		{
			root[r1+2][c1+1].visit=1;
			root[r1+2][c1+1].step=tstep+1;
			root[r1+2][c1+1].min=tmin<min[r1+2][c1+1]?tmin:min[r1+2][c1+1];
			e++;
			r[e]=r1+2;
			c[e]=c1+1;
		}
		else if(r1<rt-1&&c1<ct&&root[r1+2][c1+1].step==tstep+1&&root[r1+2][c1+1].min>tmin)
			root[r1+2][c1+1].min=tmin;
		if(r1<rt&&c1<ct-1&&root[r1+1][c1+2].visit==0)
		{
			root[r1+1][c1+2].visit=1;
			root[r1+1][c1+2].step=tstep+1;
			root[r1+1][c1+2].min=tmin<min[r1+1][c1+2]?tmin:min[r1+1][c1+2];
			e++;
			r[e]=r1+1;
			c[e]=c1+2;
		}
		else if(r1<rt&&c1<ct-1&&root[r1+1][c1+2].step==tstep+1&&root[r1+1][c1+2].min>tmin)
			root[r1+1][c1+2].min=tmin;
		if(r1>1&&c1<ct-1&&root[r1-1][c1+2].visit==0)
		{
			root[r1-1][c1+2].visit=1;
			root[r1-1][c1+2].step=tstep+1;
			root[r1-1][c1+2].min=tmin<min[r1-1][c1+2]?tmin:min[r1-1][c1+2];
			e++;
			r[e]=r1-1;
			c[e]=c1+2;
		}
		else if(r1>1&&c1<ct-1&&root[r1-1][c1+2].step==tstep+1&&root[r1-1][c1+2].min>tmin)
			root[r1-1][c1+2].min=tmin;
		if(r1>2&&c1<ct&&root[r1-2][c1+1].visit==0)
		{
			root[r1-2][c1+1].visit=1;
			root[r1-2][c1+1].step=tstep+1;
			root[r1-2][c1+1].min=tmin<min[r1-2][c1+1]?tmin:min[r1-2][c1+1];
			e++;
			r[e]=r1-2;
			c[e]=c1+1;
		}
		else if(r1>2&&c1<ct&&root[r1-2][c1+1].step==tstep+1&&root[r1-2][c1+1].min>tmin)
			root[r1-2][c1+1].min=tmin;
		if(r1>2&&c1>1&&root[r1-2][c1-1].visit==0)
		{
			root[r1-2][c1-1].visit=1;
			root[r1-2][c1-1].step=tstep+1;
			root[r1-2][c1-1].min=tmin<min[r1-2][c1-1]?tmin:min[r1-2][c1-1];
			e++;
			r[e]=r1-2;
			c[e]=c1-1;
		}
		else if(r1>2&&c1>1&&root[r1-2][c1-1].step==tstep+1&&root[r1-2][c1-1].min>tmin)
			root[r1-2][c1-1].min=tmin;
		if(r1>1&&c1>2&&root[r1-1][c1-2].visit==0)
		{
			root[r1-1][c1-2].visit=1;
			root[r1-1][c1-2].step=tstep+1;
			root[r1-1][c1-2].min=tmin<min[r1-1][c1-2]?tmin:min[r1-1][c1-2];
			e++;
			r[e]=r1-1;
			c[e]=c1-2;
		}
		else if(r1>1&&c1>2&&root[r1-1][c1-2].step==tstep+1&&root[r1-1][c1-2].min>tmin)
			root[r1-1][c1-2].min=tmin;
	}	
}

int main()
{
	int i,j,k,mm,t1,t2,tot;
	FILE *fin  = fopen ("camelot.in", "r");
    FILE *fout = fopen ("camelot.out", "w");
	fscanf(fin,"%d %d",&rt,&ct);
	fscanf(fin,"%s %d",R,&C);
	col=*R-'A'+1;
	row=C;
	tot=0;
	while((fscanf(fin,"%s %d",R,&C))!=EOF)
	{
		tot++;
		knight[tot].col=*R-'A'+1;
		knight[tot].row=C;
	}
	for(i=1;i<=rt;i++)
	{
		t1=i<row?row-i:i-row;
		for(j=1;j<=ct;j++)
		{
			t2=j<col?col-j:j-col;
			min[i][j]=t1>t2?t1:t2;
		}
	}
	for(i=1,step=99999999;i<=rt;i++)
	{
		for(j=1,kingmove=99999999;j<=ct;j++,kingmove=99999999)
		{
			find(i,j);
			cstep=0;
			for(k=1;k<=tot;k++)
			{
				cstep+=root[knight[k].row][knight[k].col].step;
				if(root[knight[k].row][knight[k].col].visit==0)
				{
					cstep=999999;
					break;
				}
				if(root[knight[k].row][knight[k].col].min<kingmove)
					kingmove=root[knight[k].row][knight[k].col].min;
			}
			cstep+=kingmove;
			if(cstep<step)
				step=cstep;
		}
	}	
	if(tot==0)
		step=min[row][col];
	fprintf(fout,"%d\n",step);
	return 0;
}
