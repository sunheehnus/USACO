/*
ID: sunheco1
LANG: C
TASK: tour
*/
#include<stdio.h>
#include<string.h>
char city[128][16];
int citynum;
char islink[128][128];
int linknum;

int dp[128][128];

int equal(char *p1,char *p2)
{
	while(*p1==*p2&&*p1!='\0')
	{
		p1++;
		p2++;
	}
	return *p1==*p2;
}

int pos(char *p)
{
	int i;
	for(i=1;i<=citynum;i++)
	{
		if(equal(p,&city[i][0]))
		{
			return i;
		}
	}
	return -1;
}

int find(int i,int j)
{
	int k;
	for(k=1;k<j;k++)
	{
		if(dp[i][k]&&islink[k][j]&&dp[i][k]+1>dp[i][j])
		{
			dp[i][j]=dp[i][k]+1;
		}
	}
	return dp[i][j];
}

int main()
{
	int i,j,source,sink,result;
	char tmp1[16],tmp2[16];
	FILE *fin  = fopen ("tour.in", "r");
    FILE *fout = fopen ("tour.out", "w");
	fscanf(fin,"%d %d",&citynum,&linknum);
	for(i=1;i<=citynum;i++)
	{
		fscanf(fin,"%s",&city[i][0]);
	}
	for(i=1;i<=linknum;i++)
	{
		fscanf(fin,"%s %s",tmp1,tmp2);
		source=pos(tmp1);
		sink=pos(tmp2);
		if(source>sink)
		{
			source^=sink;
			sink^=source;
			source^=sink;
		}
		islink[source][sink]=1;
	}
	for(i=1,dp[1][1]=1;i<citynum;i++)
	{
		for(j=i+1;j<=citynum;j++)
		{
			dp[i][j]=dp[j][i]=find(i,j);
		}
	}
	result=find(citynum,citynum);
	if(result==0)
		result=1;
	else
		result-=1;
	fprintf(fout,"%d\n",result);
	return 0;
}
