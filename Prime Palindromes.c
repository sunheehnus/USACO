/*
ID: sunheco1
LANG: C
TASK: pprime
*/
#include<stdio.h>
int start,end,max,min,total,current;
int map[10001],pri[10001],st[100],out[1000];
void Initial()
{	
	int i,j;
	for(i=2;i<=10000;i++)
	{
		if(map[i])
			continue;
		for(j=2*i;j<=10000;j+=i)
			map[j]=1;
	}
	for(i=2,total=1;i<=10000;i++)
	{
		if(!map[i])
			pri[total++]=i;
	}
	total--;
}
int Is(int i)
{
	int j=i>>1,k;
	if(i<min||i>max)
		return 0;
	for(k=1;k<=total&&pri[k]<=j;k++)
	{
		if(!(i%pri[k]))
			return 0;
	}
	return 1;
}
void find(int now,int total)
{
	int temp,mul,i,j;
	if(total==1)
	{
		for(temp=0,mul=1,j=1;j<now;j++,mul=(mul<<3)+(mul<<1))
			temp=(temp<<3)+(temp<<1)+st[j];
		temp=(temp<<3)+(temp<<1);
		for(j--;j>0;j--)
			temp=(temp<<3)+(temp<<1)+st[j];
		for(j=0;j<=9;j++)
		{
			i=j*mul;
			temp+=i;
			if(Is(temp))
				out[++current]=temp;
			temp-=i;
		}
	}
	else if(total==2)
	{
		for(temp=0,mul=1,j=1;j<now;j++,mul=(mul<<3)+(mul<<1))
			temp=(temp<<3)+(temp<<1)+st[j];
		temp=(temp<<6)+(temp<<5)+(temp<<2);
		for(j--;j>0;j--)
			temp=(temp<<3)+(temp<<1)+st[j];
		for(j=0;j<=9;j++)
		{
			i=((j<<3)+(j<<1)+j)*mul;
			temp+=i;
			if(Is(temp))
				out[++current]=temp;
			temp-=i;
		}
	}
	else
	{
		for(i=0;i<=9;i++)
		{
			st[now]=i;
			find(now+1,total-2);
		}
	}
}

int main()
{
	int a,b,temp,i;
	FILE *fin  = fopen ("pprime.in", "r");
	FILE *fout = fopen ("pprime.out", "w");
	Initial();
	fscanf(fin,"%d %d",&min,&max);
	a=min;
	while(a)
	{
		start++;
		a/=10;
	}
	b=max;
	while(b)
	{
		end++;
		b/=10;
	}
	if(b==9)
		b--;
	for(i=2;i<10;i++)
	{
		if(Is(i))
			out[++current]=i;
	}
	for(i=1;i<=9;i++)
	{
		temp=i*10+i;
		if(Is(temp))
			out[++current]=temp;
	}
	if(start<3)
		start=3;
	for(;start<=end;start++)
	{
		for(i=1;i<=9;i+=2)
		{
			st[1]=i;
			find(2,start-2);
		}
	}
	for(i=1;i<=current;i++)
		fprintf(fout,"%d\n",out[i]);
	return 0;
}