/*
ID: sunheco1
LANG: C
TASK: twofive
*/
#include<stdio.h>

int Memo[6][6][6][6][6];

int map[6][6];

int pos;

char out[32],visit[32];

int Finish;

int lev[6];

int DP(int lev1,int lev2,int lev3,int lev4,int lev5)
{
	int sum;
	if(Memo[lev1][lev2][lev3][lev4][lev5]!=0)
		return Memo[lev1][lev2][lev3][lev4][lev5];
	sum=0;
	if(lev1<5)
	{
		sum+=DP(lev1+1,lev2,lev3,lev4,lev5);
	}
	if(lev2<lev1)
	{
		sum+=DP(lev1,lev2+1,lev3,lev4,lev5);
	}
	if(lev3<lev2)
	{
		sum+=DP(lev1,lev2,lev3+1,lev4,lev5);
	}
	if(lev4<lev3)
	{
		sum+=DP(lev1,lev2,lev3,lev4+1,lev5);
	}
	if(lev5<lev4)
	{
		sum+=DP(lev1,lev2,lev3,lev4,lev5+1);
	}
	Memo[lev1][lev2][lev3][lev4][lev5]=sum;
	return sum;
}

int OK(int i,int r,int c)
{
	if(i<map[r-1][c]||i<map[r][c-1])
		return 0;
	return 1;
}

int add(int left)
{
	int i,j,tmp;
	if(left==0)
		return Memo[lev[1]][lev[2]][lev[3]][lev[4]][lev[5]];
	tmp=0;
	for(i=2;visit[i]==1;i++);
	visit[i]=1;
	for(j=1;j<=5;j++)
	{
		if(lev[j]==lev[j-1])
			continue;
		if(lev[j]<5&&OK(i,j,lev[j]+1))
		{
			lev[j]++;
			map[j][lev[j]]=i;
			tmp+=add(left-1);
			lev[j]--;
		}
	}
	visit[i]=0;
	return tmp;
}

int SUM()
{
	int MAX;
	for(MAX=24;visit[MAX]==0;MAX--);
	return add(MAX-lev[1]-lev[2]-lev[3]-lev[4]-lev[5]);
}

char Findstr(int now)
{
	int i,r,c,tmp;
	r=now%5==0?now/5:now/5+1;
	c=now%5==0?5:now%5;
	for(i=2;i<25;i++)
	{
		if(!visit[i]&&OK(i,r,c))
		{
			visit[i]=1;
			lev[r]++;
			map[r][c]=i;
			tmp=SUM();
			if(tmp<pos)
			{
				pos-=tmp;
				visit[i]=0;
				lev[r]--;
			}
			else
			{
				return 'A'+i-1;
			}
		}
	}
}

void Findpos(int max,int now)
{
	int i,r,c,tmp;
	r=now%5==0?now/5:now/5+1;
	c=now%5==0?5:now%5;
	for(i=2;i<max;i++)
	{
		if(!visit[i]&&OK(i,r,c))
		{
			visit[i]=1;
			lev[r]++;
			map[r][c]=i;
			tmp=SUM();
			pos+=tmp;
			lev[r]--;
			visit[i]=0;
		}
	}
	visit[max]=1;
	map[r][c]=max;
	lev[r]++;
}
/*
int Findpos(int now)
{ 
	int i,j;
	int lev[6];
	lev[1]=lev[2]=lev[3]=lev[4]=lev[5]=0;
	for(i=1;i<=now/5;i++)
		lev[i]=5;
	lev[i]=now%5;
	for(j=1,i=0;j<=25&&j!=out[now]-'A'+1;j++)
	{
		if(!visit[j])
		{
			i++;
		}
	}
	visit[j]=1;
	return Memo[lev[1]][lev[2]][lev[3]][lev[4]][lev[5]]*i;
}
*/
int main()
{
	int i;
	FILE *fin  = fopen ("twofive.in", "r");
    FILE *fout = fopen ("twofive.out", "w");
	Memo[5][5][5][5][5]=1;
	DP(1,0,0,0,0);
	fscanf(fin,"%s",out);
	if(out[0]=='N')
	{
		fscanf(fin,"%d",&pos);
		map[1][1]=1;
		map[5][5]=25;
		out[1]='A';
		visit[1]=1;
		out[25]='Y';
		visit[25]=1;
		lev[1]=1;
		for(i=2;i<25;i++)
			out[i]=Findstr(i);
		fprintf(fout,"%s\n",out+1);
	}
	else if(out[0]=='W')
	{
		fscanf(fin,"%s",out+1);
		map[1][1]=1;
		map[5][5]=25;
		visit[1]=1;
		visit[25]=1;
		lev[1]=1;
		for(i=2;i<25;i++)
		{
			Findpos(out[i]-'A'+1,i);
		}
		fprintf(fout,"%d\n",pos+1);
	}
	return 0;
}
//ABCDEFGHIJKLMNOPQRSTUVWXY
//ACFDKBGELRHJMNOIPSTXQUVWY