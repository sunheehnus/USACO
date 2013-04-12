/*
ID: sunheco1
LANG: C
TASK: frameup
*/
#include<stdio.h>
#include<string.h>
char map[32][32],visit[32],is[32],left[32],right[32],ceil[32],floor[32],topical[32][32],opposite[32][32],degree[32];

char level[32][32],output[32];

int H,W,start[32],end[32],total;

FILE *fin;
FILE *fout;

int frameup(int k1,int k2)
{
	int l1,r1,f1,c1,l2,r2,f2,c2,i,l,h,now;
	l1=left[k1];
	r1=right[k1];
	f1=floor[k1];
	c1=ceil[k1];
	l2=left[k2];
	r2=right[k2];
	f2=floor[k2];
	c2=ceil[k2];
	if(l1>l2&&l1<r2)
	{
		if(c1<c2&&f1>c2&&map[c2][l1]!='@'||c1<f2&&f1>f2&&map[f2][l1]!='@')
			return 1;
	}
	if(r1>l2&&r1<r2)
	{
		if(c1<c2&&f1>c2&&map[c2][r1]!='@'||c1<f2&&f1>f2&&map[f2][r1]!='@')
			return 1;
	}
	if(l2>l1&&l2<r1)
	{
		if(c2<c1&&f2>c1&&map[c1][l2]!='@'||c2<f1&&f2>f1&&map[f1][l2]!='@')
			return 1;
	}
	if(r2>l1&&r2<r1)
	{
		if(c2<c1&&f2>c1&&map[c1][r2]!='@'||c2<f1&&f2>f1&&map[f1][r2]!='@')
			return 1;
	}
	if(c1>c2&&c1<f2)
	{
		if(l1<l2&&r1>l2&&map[c1][l2]!='@'||l1<r2&&r1>r2&&map[c1][r2]!='@')
			return 1;
	}
	if(f1>c2&&f1<f2)
	{
		if(l1<l2&&r1>l2&&map[f1][l2]!='@'||l1<r2&&r1>r2&&map[f1][r2]!='@')
			return 1;
	}
	if(c2>c1&&c2<f1)
	{
		if(l2<l1&&r2>l1&&map[c2][l1]!='@'||l2<r1&&r2>r1&&map[c2][r1]!='@')
			return 1;
	}
	if(f2>c1&&f2<f1)
	{
		if(l2<l1&&r2>l1&&map[f2][l1]!='@'||l2<r1&&r2>r1&&map[f2][r1]!='@')
			return 1;
	}
	if(c1==c2||c1==f2)
	{
		l=l1>l2?l1:l2;
		h=r1<r2?r1:r2;
		for(i=l;i<=h;i++)
		{
			if(map[c1][i]!='@')
				return 1;
		}
	}
	if(f1==c2||f1==f2)
	{
		l=l1>l2?l1:l2;
		h=r1<r2?r1:r2;
		for(i=l;i<=h;i++)
		{
			if(map[f1][i]!='@')
				return 1;
		}
	}
	if(l1==l2||l1==r2)
	{
		l=c1>c2?c1:c2;
		h=f1<f2?f1:f2;
		for(i=l;i<=h;i++)
		{
			if(map[i][l1]!='@')
				return 1;
		}
	}
	if(r1==l2||r1==r2)
	{
		l=c1>c2?c1:c2;
		h=f1<f2?f1:f2;
		for(i=l;i<=h;i++)
		{
			if(map[i][r1]!='@')
				return 1;
		}
	}
	return 0;
}

void Updata(int key)
{
	int l,r,f,c,i;
	l=left[key];
	r=right[key];
	f=floor[key];
	c=ceil[key];
	for(i=l;i<=r;i++)
	{
		map[f][i]=map[c][i]='@';
	}
	for(i=c;i<=f;i++)
	{
		map[i][l]=map[i][r]='@';
	}
}

void Up(int key)
{
	int i;
	for(i=0;i<27;i++)
	{
		if(!visit[i]&&frameup(i,key))
		{
			opposite[key][i]=1;
			topical[i][key]=1;
		}
	}
}

int Yes(int key)
{
	int l,r,f,c,i,j;
	l=left[key];
	r=right[key];
	f=floor[key];
	c=ceil[key];
	for(i=l;i<=r;i++)
	{
		if((map[f][i]!=key+'A'&&map[f][i]!='@')||(map[c][i]!=key+'A'&&map[c][i]!='@'))
			return 0;
	}
	for(i=c;i<=f;i++)
	{
		if((map[i][l]!=key+'A'&&map[i][l]!='@')||(map[i][r]!=key+'A'&&map[i][r]!='@'))
			return 0;
	}
	
	return 1;
}

void find(int rank)
{
	int i,flag;
	for(i=0,flag=0;i<27;i++)
	{
 		if(!visit[i]&&Yes(i))
		{
			level[rank][0]++;
			level[rank][level[rank][0]]='A'+i;
			visit[i]=1;
			flag=1;
		}
	}
	if(flag==0)
	{
		return;
	}
	for(i=1;i<=level[rank][0];i++)
	{
		Up(level[rank][i]-'A');
	}
	for(i=1;i<=level[rank][0];i++)
	{
		Updata(level[rank][i]-'A');
	}
	find(rank+1);
}

void swap(int i,int j)
{
	if(i==j)
		return;
	output[i]=output[i]^output[j];
	output[j]=output[i]^output[j];
	output[i]=output[i]^output[j];
}


void Output(int now)
{
	int i,j,flag;
	if(now==total)
		fprintf(fout,"%s\n",output+1);
	for(i=now;i<=total;i++)
	{
		flag=0;
		for(j=0;j<27;j++)
		{
			if(is[j]==0&&opposite[output[i]-'A'][j])
			{
				flag=1;
				break;
			}
		}	
		if(flag==1)
			continue;
		swap(now,i);
		for(j=i;j>now+1;j--)
			swap(j,j-1);
		is[output[now]-'A']=1;
		Output(now+1);
		is[output[now]-'A']=0;
		for(j=now+1;j<i;j++)
			swap(j,j+1);
		swap(now,i);
	}
}

int main()
{
	int i,j,cnt;
	fin  = fopen ("frameup.in", "r");
    fout = fopen ("frameup.out", "w");
	fscanf(fin,"%d %d",&H,&W);
	memset(left,0x7f,sizeof(left));
	memset(ceil,0x7f,sizeof(ceil));
	memset(visit,1,sizeof(visit));
	memset(is,1,sizeof(is));
	for(i=1;i<=H;i++)
	{
		fscanf(fin,"%s",&map[i][1]);
	}
	for(i=1;i<=H;i++)
	{
		for(j=1;j<=W;j++)
		{
			if(map[i][j]>='A'&&map[i][j]<='Z')
			{
				if(left[map[i][j]-'A']>j)
					left[map[i][j]-'A']=j;
				if(right[map[i][j]-'A']<j)
					right[map[i][j]-'A']=j;
				if(ceil[map[i][j]-'A']>i)
					ceil[map[i][j]-'A']=i;
				if(floor[map[i][j]-'A']<i)
					floor[map[i][j]-'A']=i;
				visit[map[i][j]-'A']=0;
				is[map[i][j]-'A']=0;
			}	
		}
	}
	find(1);
	for(i=0;i<27;i++)
	{
		for(j=0;j<27;j++)
		{                  
			degree[j]+=topical[i][j];
		}
	}
	for(i=0,total=0;i<27;i++)
	{
		if(is[i]==0)
		{
			output[++total]=i+'A';
		}
	}
	Output(1);
	return 0;
}


