/*
ID: sunheco1
LANG: C
TASK: starry
*/
#include<stdio.h>
#include<string.h>

char skymap[128][128],visit[128][128],output[128][128],atoz[27][9][128][128],tmap[128][128],tmp[128][128],mm[128][128];

int cmp[27],total,ni,nj,cmn,w,h,l,r,u,d,total;

struct SM{char w,h;}wh[27][9];

void Updata(int i,int j,char a)
{
	if(i<1||j<1||i>h||j>w||skymap[i][j]=='0'||output[i][j]==a)
		return;
	output[i][j]=a;
	Updata(i-1,j-1,a);
	Updata(i-1,j,a);
	Updata(i-1,j+1,a);
	Updata(i,j-1,a);
	Updata(i,j+1,a);
	Updata(i+1,j-1,a);
	Updata(i+1,j,a);
	Updata(i+1,j+1,a);
}

void search(int i,int j)
{
	if(i<1||j<1||i>h||j>w||skymap[i][j]=='0'||visit[i][j]==1)
		return;
	if(i<u)
		u=i;
	if(i>d)
		d=i;
	if(j<l)
		l=j;
	if(j>r)
		r=j;
	visit[i][j]=1;
	search(i-1,j-1);
	search(i-1,j);
	search(i-1,j+1);
	search(i,j-1);
	search(i,j+1);
	search(i+1,j-1);
	search(i+1,j);
	search(i+1,j+1);
}

void make(int i,int j)
{
	if(i<1||j<1||i>ni||j>nj||tmp[i][j]=='0'||tmap[i][j]==1)
		return;
	tmap[i][j]=1;
	make(i-1,j-1);
	make(i-1,j);
	make(i-1,j+1);
	make(i,j-1);
	make(i,j+1);
	make(i+1,j-1);
	make(i+1,j);
	make(i+1,j+1);
}	

int Judge()
{
	int i,j,flag,k1,k2;
	for(i=1;i<=total;i++)
	{
		if(cmp[i]!=cmn)
			continue;
		for(j=1;j<=8;j++)
		{
			if(wh[i][j].w!=nj||wh[i][j].h!=ni)
				continue;
			for(k1=1,flag=0;k1<=ni;k1++)
			{
				if(flag==1)
					break;
				for(k2=1;k2<=nj;k2++)
				{
					if(atoz[i][j][k1][k2]!=tmap[k1][k2])
					{
						flag=1;
						break;
					}
				}
			}
			if(flag==0)
				return i;
		}
	}
	total++;
	cmp[total]=cmn;
	for(i=1;i<=ni;i++)
	{
		for(j=1;j<=nj;j++)
		{
			atoz[total][1][i][j]=tmap[i][j];
			atoz[total][2][nj-j+1][i]=tmap[i][j];
			atoz[total][3][ni-i+1][nj-j+1]=tmap[i][j];
			atoz[total][4][j][ni-i+1]=tmap[i][j];
		}
	}
	for(i=1;i<=ni;i++)
	{
		for(j=1;j<=nj;j++)
		{
			atoz[total][5][i][nj-j+1]=atoz[total][1][i][j];
			atoz[total][7][i][nj-j+1]=atoz[total][3][i][j];
		}
	}
	for(i=1;i<=nj;i++)
	{
		for(j=1;j<=ni;j++)
		{
			atoz[total][6][i][ni-j+1]=atoz[total][2][i][j];
			atoz[total][8][i][ni-j+1]=atoz[total][4][i][j];
		}
	}
	wh[total][1].w=nj;
	wh[total][1].h=ni;
	wh[total][2].w=ni;
	wh[total][2].h=nj;
	wh[total][3].w=nj;
	wh[total][3].h=ni;
	wh[total][4].w=ni;
	wh[total][4].h=nj;
	wh[total][5].w=nj;
	wh[total][5].h=ni;
	wh[total][6].w=ni;
	wh[total][6].h=nj;
	wh[total][7].w=nj;
	wh[total][7].h=ni;
	wh[total][8].w=ni;
	wh[total][8].h=nj;
	return 0;
}

int main()
{
	int i,j,k1,k2,al;
	FILE *fin  = fopen ("starry.in", "r");
    FILE *fout = fopen ("starry.out", "w");
	fscanf(fin,"%d %d",&w,&h);
	for(i=1;i<=h;i++)
	{
		fscanf(fin,"%s",&skymap[i][1]);
	}
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
		{
			output[i][j]='0';
		}
	}
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(visit[i][j])
				continue;
			if(skymap[i][j]=='0')
				visit[i][j]=1;
			else
			{
				r=d=0;
				l=u=1000;
				search(i,j);
				memset(tmp,0,sizeof(tmp));
				memset(tmap,0,sizeof(tmap));
				for(k1=u;k1<=d;k1++)
				{
					for(k2=l;k2<=r;k2++)
					{
						tmp[k1-u+1][k2-l+1]=skymap[k1][k2];
					}
				}	
				ni=d-u+1;
				nj=r-l+1;
				make(i-u+1,j-l+1);	
				cmn=(ni<<8|nj)<(nj<<8|ni)?(ni<<8|nj):(nj<<8|ni);
				al=Judge();
				if(al==0)
				{
					Updata(i,j,'a'+total-1);
				}
				else
				{
					Updata(i,j,'a'+al-1);
				}
			}
		}
	}
	for(i=1;i<=h;i++)
	{
		fprintf(fout,"%s\n",&output[i][1]);
	}
	return 0;
}