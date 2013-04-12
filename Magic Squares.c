/*
ID: sunheco1
LANG: C
TASK: msquare
*/
#include<stdio.h>

#define N 8

char output[40321];

int num[9]={0,1,2,3,4,5,6,7,8,};

int tot;

struct Root{int step,pre;char means,visit;};

struct Queue{int now,step;};

struct Root root[40321];

struct Queue queue[65536];

unsigned int map[55555];

unsigned int A(unsigned int a)
{
	a=((a>>4)&0x0F0F0F0F)|((a<<4)&0xF0F0F0F0);
	a=((a>>8)&0x00FF00FF)|((a<<8)&0xFF00FF00);
	a=((a>>16)&0x0000FFFF)|((a<<16)&0xFFFF0000);
	return a;
}

unsigned int B(unsigned int b)
{
	b=((b&0x0FF00000)>>4)|((b&0x00000FF0)<<4)|((b&0xF0000000)>>4)|((b&0x000F0000)<<12)|((b&0x0000F000)>>12)|((b&0x0000000F)<<4);
	return b;
}

unsigned int C(unsigned c)
{
	c=(c&0xF00FF00F)|((c&0x0F000000)>>4)|((c&0x00F00000)>>12)|((c&0x00000F00)>>4)|((c&0x000000F0)<<20);
	return c;
}

int find(unsigned int tar)
{
	int s=1,e=40320,mid=(s+e)>>1;
	while(map[mid]!=tar)
	{
		if(map[mid]>tar)
			e=mid-1;
		else
			s=mid+1;
		mid=(s+e)>>1;
	}
	return mid;
}

void swap(int i,int j)
{
	int temp;
	temp=num[i];
	num[i]=num[j];
	num[j]=temp;
}

void make(int level)
{
	int i,k,temp;
	if(level==N)
	{
		tot++;
		map[tot]=(num[8]&0xF)|((num[7]&0xF)<<4)|((num[6]&0xF)<<8)|((num[5]&0xF)<<12)|((num[4]&0xF)<<16)|((num[3]&0xF)<<20)|((num[2]&0xF)<<24)|((num[1]&0xF)<<28);
		return;
	}
	//make(level+1);
	temp=num[level];
	for(i=level;i<=N;i++)
	{		
		swap(level,i);
		for(k=i;k>level+1;k--)
			num[k]=num[k-1];
		num[k]=temp;
		make(level+1);
		for(;k<i;k++)
			num[k]=num[k+1];
		num[k]=temp;
		swap(level,i);
	}
}

int main()
{
	int i,target,s,e,abc,step,now;
	unsigned input;
	FILE *fin  = fopen ("msquare.in", "r");
    FILE *fout = fopen ("msquare.out", "w");
	for(i=1,input=0;i<=8;i++)
	{
		fscanf(fin,"%d",&now);
		input|=now<<(8-i<<2);
	}
	make(1);
	target=find(input);
	if(target==1)
	{
		fprintf(fout,"0\n\n");
		return 0;
	}
	root[1].visit=1;
	queue[0].now=1;
	queue[0].step=0;
	s=0;
	e=1;
	while(1)
	{
		step=queue[s].step+1;
		now=queue[s].now;
		s=(s+1)&65535;
		abc=find(A(map[now]));
		if(root[abc].visit==0)
		{
			root[abc].visit=1;
			root[abc].means='A';
			root[abc].pre=now;
			root[abc].step=step;
			if(abc==target)
				break;
			queue[e].now=abc;
			queue[e].step=step;
			e=(e+1)&65535;
		}
		abc=find(B(map[now]));
		if(root[abc].visit==0)
		{
			root[abc].visit=1;
			root[abc].means='B';
			root[abc].pre=now;
			root[abc].step=step;
			if(abc==target)
				break;
			queue[e].now=abc;
			queue[e].step=step;
			e=(e+1)&65535;
		}
		abc=find(C(map[now]));
		if(root[abc].visit==0)
		{
			root[abc].visit=1;
			root[abc].means='C';
			root[abc].pre=now;
			root[abc].step=step;
			if(abc==target)
				break;
			queue[e].now=abc;
			queue[e].step=step;
			e=(e+1)&65535;
		}
	}
	fprintf(fout,"%d\n",root[target].step);
	output[root[target].step+1]='\0';
	while(root[target].step)
	{
		output[root[target].step]=root[target].means;
		target=root[target].pre;
	}
	for(i=1,now=1;output[i]!='\0';i++,now++)
	{
		fprintf(fout,"%c",output[i]);
		if(now==60)
		{
			fprintf(fout,"\n");
			now=0;
		}
	}
	if(now!=1)
		fprintf(fout,"\n");
	return 0;
}