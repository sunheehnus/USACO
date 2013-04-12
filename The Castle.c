/*
ID: sunheco1
LANG: C
TASK: castle
*/
#include<stdio.h>
int map[55][55],room[55][55],rt[3333];
int n,m,tot,max,ci,cj,cd;
void search(int i,int j)
{
	if(room[i][j])
		return;
	room[i][j]=tot;
	rt[tot]++;
	if(!(map[i][j]&1))
	{
		search(i,j-1);
	}
	if(!(map[i][j]&2))
	{
		search(i-1,j);
	}
	if(!(map[i][j]&4))
	{
		search(i,j+1);
	}
	if(!(map[i][j]&8))
	{
		search(i+1,j);
	}
}
void Judge(int i,int j)
{
	int temp;
	if(map[i][j]&2)
	{
		if(room[i-1][j]&&room[i-1][j]!=room[i][j])
		{
			temp=rt[room[i][j]]+rt[room[i-1][j]];
			if(temp>max)
			{
				max=temp;
				ci=i;
				cj=j;
				cd=1;
			}
		}
	}
	if(map[i][j]&4)
	{
		if(room[i][j+1]&&room[i][j+1]!=room[i][j])
		{
			temp=rt[room[i][j]]+rt[room[i][j+1]];
			if(temp>max)
			{
				max=temp;
				ci=i;
				cj=j;
				cd=2;
			}
		}
	}
}
int main()
{
	int i,j;
	FILE *fin  = fopen ("castle.in", "r");
    FILE *fout = fopen ("castle.out", "w");
	fscanf(fin,"%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			fscanf(fin,"%d",&map[i][j]);
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(room[i][j])
				continue;
			tot++;
			search(i,j);
		}
	}
	fprintf(fout,"%d\n",tot);
	for(i=1,max=0;i<=tot;i++)
	{
		if(rt[i]>max)
			max=rt[i];
	}
	fprintf(fout,"%d\n",max);
	for(j=1,max=0;j<=n;j++)
	{
		for(i=m;i>=1;i--)
		{
			Judge(i,j);
		}
	}
	fprintf(fout,"%d\n",max);
	fprintf(fout,"%d %d ",ci,cj);
	if(cd==1)
		fprintf(fout,"N\n");
	else
		fprintf(fout,"E\n");
	return 0;
}
