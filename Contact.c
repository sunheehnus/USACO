/*
ID: sunheco1
LANG: C
TASK: contact
*/
#include<stdio.h>

char in[222222],buf[20];

int result[22][5555];

struct OUT{int len,num,tot;};
struct OUT out[55555];

int A,B,N,total;

void find(int i,int now,int m)
{
	if(now>B)
		return;
	if(in[i]!='0'&&in[i]!='1')
		return;
	m=(m<<1)+in[i]-'0';
	if(now>=A)
	{
		result[now][m]++;
	}
	find(i+1,now+1,m);
}

int cmp(struct OUT s1,struct OUT s2)
{
	if(s1.tot<s2.tot)
		return 1;
	if(s1.tot==s2.tot&&s1.len>s2.len)
		return 1;
	if(s1.tot==s2.tot&&s1.len==s2.len&&s1.num>s2.num)
		return 1;
	return 0;
}

void quick_sort(int s,int e)
{
	int mid,i,j;
	struct OUT temp;
	if(s<e)
	{
		mid=(s+e)>>1;
		i=s;
		j=e;
		temp=out[mid];
		out[mid]=out[i];
		while(i<j)
		{
			while(i<j&&cmp(out[j],temp))
				j--;
			out[i]=out[j];
			while(i<j&&cmp(temp,out[i]))
				i++;
			out[j]=out[i];
		}
		out[i]=temp;
		quick_sort(s,i-1);
		quick_sort(i+1,e);
	}
}

void output(int now)
{
	struct OUT temp=out[now];
	int i;
	for(i=temp.len;i>0;i--)
	{
		buf[i]=temp.num-((temp.num>>1)<<1)+'0';
		temp.num=temp.num>>1;
	}
	buf[temp.len+1]='\0';
}

int main()
{
	char *temp=in;
	int i,j,k,otem;
	FILE *fin  = fopen ("contact.in", "r");
    FILE *fout = fopen ("contact.out", "w");
	fscanf(fin,"%d %d %d",&A,&B,&N);
	while((fgets(temp,80,fin)!=0))
	{
		while(*temp=='0'||*temp=='1')
		{
			temp++;
		}
	}
	for(i=0;in[i]=='0'||in[i]=='1';i++)
	{
		find(i,1,0);
	}
	for(i=1;i<=12;i++)
	{
		k=1<<i;
		for(j=0;j<k;j++)
		{
			if(result[i][j])
			{
				out[++total].len=i;
				out[total].num=j;
				out[total].tot=result[i][j];
			}
		}
	}
	quick_sort(1,total); 
	for(i=2,k=1;i<=total;i++)
	{
		if(out[i].tot!=out[i-1].tot)
			k++;
	}
	N=N<k?N:k;
	for(i=1,k=1;i<=N;i++)
	{
		j=out[k].tot;
		fprintf(fout,"%d\n",j);
		output(k);
		fprintf(fout,"%s",buf+1);
		otem=1;
		for(k++;out[k].tot==j;k++)
		{
			if(otem<6)
				fprintf(fout," ");
			else
			{
				fprintf(fout,"\n");
				otem=0;
			}
			output(k);
			fprintf(fout,"%s",buf+1);
			otem++;
		}
		fprintf(fout,"\n");
	}
	return 0;
}