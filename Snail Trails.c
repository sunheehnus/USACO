/*
ID: sunheco1
LANG: C
TASK: snail
*/
#include<stdio.h>
#include<string.h>

char map[128][128];

int now,max,N;

void Go1(int i,int j);
void Go2(int i,int j);
void Go3(int i,int j);
void Go4(int i,int j);

int main()
{
	int i,j,tmp1,tmp2,total;
	char tmp[16];
	FILE *fin  = fopen ("snail.in", "r");
    FILE *fout = fopen ("snail.out", "w");
	memset(map,'.',sizeof(map));
	fscanf(fin,"%d %d",&N,&total);
	for(i=1;i<=total;i++)
	{
		fscanf(fin,"%s",tmp);
		tmp1=tmp[0]-'A'+1;
		for(j=1,tmp2=0;tmp[j]!='\0';j++)
		{
			tmp2=(tmp2<<3)+(tmp2<<1);
			tmp2+=tmp[j]-'1'+1;
		}
		map[tmp2][tmp1]='#';
	}
	Go1(1,1);
	Go2(1,1);
	fprintf(fout,"%d\n",max);
	return 0;
}

void Go1(int i,int j)
{
	now++;
	map[i][j]='Y';
	if(now>max)
		max=now;
	if(j+1<=N&&map[i][j+1]=='.')
	{
		Go1(i,j+1);		
	}
	else if(j+1>N||map[i][j+1]=='#')
	{
		if(i>1&&map[i-1][j]=='.')
			Go4(i-1,j);
		if(i<N&&map[i+1][j]=='.')
			Go2(i+1,j);
	}
	map[i][j]='.';
	now--;
}
void Go2(int i,int j)
{
	now++;
	map[i][j]='Y';
	if(now>max)
		max=now;
	if(i+1<=N&&map[i+1][j]=='.')
	{		
		Go2(i+1,j);		
	}
	else if(i+1>N||map[i+1][j]=='#')
	{
		if(j>1&&map[i][j-1]=='.')
			Go3(i,j-1);
		if(j<N&&map[i][j+1]=='.')
			Go1(i,j+1);
	}
	map[i][j]='.';
	now--;
}
void Go3(int i,int j)
{
	now++;
	map[i][j]='Y';
	if(now>max)
		max=now;
	if(j-1>=1&&map[i][j-1]=='.')
	{		
		Go3(i,j-1);		
	}
	else if(j-1<1||map[i][j-1]=='#')
	{
		if(i>1&&map[i-1][j]=='.')
			Go4(i-1,j);
		if(i<N&&map[i+1][j]=='.')
			Go2(i+1,j);
	}
	map[i][j]='.';
	now--;
}
void Go4(int i,int j)
{
	now++;
	map[i][j]='Y';
	if(now>max)
		max=now;
	if(i-1>=1&&map[i-1][j]=='.')
	{		
		Go4(i-1,j);		
	}
	else if(i-1<1||map[i-1][j]=='#')
	{
		if(j>1&&map[i][j-1]=='.')
			Go3(i,j-1);
		if(j<N&&map[i][j+1]=='.')
			Go1(i,j+1);
	}
	map[i][j]='.';
	now--;
}