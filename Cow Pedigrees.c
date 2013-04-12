/*
ID: sunheco1
LANG: C
TASK: nocows
*/
#include<stdio.h>

int dp[111][222],dp1[111][222];

int tot,level;

int Dp(int now,int total)
{
	int i,temp1,temp2;
	if(dp[now][total])
		return dp[now][total];
	if(total==0)
	{
		dp[now][total]=1;
		return 1;
	}
	if(level-now<=10&&(1<<level-now)-1==total)
	{
		dp[now][total]=1;
		return 1;
	}
	if(level-now<=10&&(1<<level-now)-1<total)
	{
		dp[now][total]=-1;
		return -1;
	}
	for(i=0;i<=total-1;i++)
	{
		temp1=Dp(now+1,i);
		temp2=Dp(now+1,total-1-i);
		if(temp1!=-1&&temp2!=-1)
		{
			dp[now][total]+=temp1*temp2;
			dp[now][total]%=9901;
		}
	}
	if(!dp[now][total])
		dp[now][total]=-1;
	return dp[now][total];
}
int Dp1(int now,int total)
{
	int i,temp1,temp2;
	if(dp1[now][total])
		return dp1[now][total];
	if(total==0)
	{
		dp1[now][total]=1;
		return 1;
	}
	if(level-now<=10&&(1<<level-now)-1<=total)
	{
		dp1[now][total]=-1;
		return -1;
	}
	for(i=0;i<=total-1;i++)
	{
		temp1=Dp1(now+1,i);
		temp2=Dp1(now+1,total-1-i);
		if(temp1!=-1&&temp2!=-1)
		{
			dp1[now][total]+=temp1*temp2;
			dp1[now][total]%=9901;
		}
	}
	if(!dp1[now][total])
		dp1[now][total]=-1;
	return dp1[now][total];
}

int main()
{
	int tar1,tar2;
	FILE *fin  = fopen ("nocows.in", "r");
    FILE *fout = fopen ("nocows.out", "w");
	fscanf(fin,"%d %d",&tot,&level);
	if(!(tot&1))
		tot=0;
	tot>>=1;
	if(tot>=level-1)
	{
		tar1=Dp(1,tot);
		tar2=Dp1(1,tot);
		tar2=tar2>0?tar2:0;
		tar1-=tar2;
		tar1+=9901;
		tar1%=9901;
		fprintf(fout,"%d\n",tar1);
	}
	else
		fprintf(fout,"0\n");
	return 0;
}

