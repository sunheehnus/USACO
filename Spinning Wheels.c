/*
ID: sunheco1
LANG: C
TASK: spin
*/
#include<stdio.h>

int speed[6],total[6],st[6][6],ed[6][6],s,e,st1,ed1,st2,ed2,st3,ed3,add;

struct Yes{int st,ed;}yes[2222];
struct Judge{int s1,e1,s2,e2,s3,e3,s4,e4,s5,e5;}judge[99999];

int tot;

int check()
{
	int i;
	for(i=1;i<=tot;i++)
	{
		if(st[1][1]==judge[i].s1&&st[2][1]==judge[i].s2&&st[3][1]==judge[i].s3&&st[4][1]==judge[i].s4&&st[5][1]==judge[i].s5&&ed[1][1]==judge[i].e1&&ed[2][1]==judge[i].e2&&ed[3][1]==judge[i].e3&&ed[4][1]==judge[i].e4&&ed[5][1]==judge[i].e5)
			return 0;
	}
	return 1;
}

void insert()
{
	tot++;
	judge[tot].s1=st[1][1];
	judge[tot].s2=st[2][1];
	judge[tot].s3=st[3][1];
	judge[tot].s4=st[4][1];
	judge[tot].s5=st[5][1];
	judge[tot].e1=ed[1][1];
	judge[tot].e2=ed[2][1];
	judge[tot].e3=ed[3][1];
	judge[tot].e4=ed[4][1];
	judge[tot].e5=ed[5][1];
}

void updata()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=total[i];j++)
		{
			st[i][j]=(st[i][j]+speed[i])%360;
			ed[i][j]=(ed[i][j]+speed[i])%360;
		}
	}
}

int OK()
{
	int i,j,k,s,e,st1,ed1,st2,ed2,st3,ed3,now,add;
	s=1;
	e=0;
	for(i=1;i<=total[1];i++)
	{
		if(st[1][i]>ed[1][i])
		{
			e++;
			yes[e].st=st[1][i];
			yes[e].ed=359;
			e++;
			yes[e].st=0;
			yes[e].ed=ed[1][i];
		}
		else
		{
			e++;
			yes[e].st=st[1][i];
			yes[e].ed=ed[1][i];
		}
	}
	for(i=2;i<=5;i++)
	{
		add=0;
		for(k=s;k<=e;k++)
		{
			st1=yes[k].st;
			ed1=yes[k].ed;
			for(j=1;j<=total[i];j++)
			{
				st2=st[i][j];
				ed2=ed[i][j];
				if(st2>ed2)
				{
					st3=st1>st2?st1:st2;
					ed3=ed1<359?ed1:359;
					if(st3<=ed3)
					{
						add++;
						yes[e+add].st=st3;
						yes[e+add].ed=ed3;
					}
					st3=st1>0?st1:0;
					ed3=ed1<ed2?ed1:ed2;
					if(st3<=ed3)
					{
						add++;
						yes[e+add].st=st3;
						yes[e+add].ed=ed3;
					}
				}
				else
				{
					st3=st1>st2?st1:st2;
					ed3=ed1<ed2?ed1:ed2;
					if(st3<=ed3)
					{
						add++;
						yes[e+add].st=st3;
						yes[e+add].ed=ed3;
					}
				}
			}
		}
		if(add==0)
			return 0;
		s=e+1;
		e+=add;
	}
	return 1;
}

int main()
{
	int i,j,cnt,find,ST,EX;
	FILE *fin  = fopen ("spin.in", "r");
    FILE *fout = fopen ("spin.out", "w");
	for(i=1;i<=5;i++)
	{
 		fscanf(fin,"%d %d",speed+i,total+i);
		for(j=1;j<=total[i];j++)
		{
			fscanf(fin,"%d %d",&ST,&EX);
			st[i][j]=ST;
			ed[i][j]=(ST+EX)%360;
		}
	}
	cnt=-1;
	find=0;
	while(1)
	{
		cnt++;
		if(OK())
		{
			find=1;	
			break;
		}
		if(check())
		{
			insert();
			updata();
		}
		else
		{
			find=0;
			break;
		}
	}
	if(find)
	{
		fprintf(fout,"%d\n",cnt);
	}
	else
	{
		fprintf(fout,"none\n");
	}
	return 0;
}