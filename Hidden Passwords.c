/*
ID: sunheco1
LANG: C
TASK: hidden 
*/

#include <stdio.h>
int max,start;
char tar[200002];
int sa[200002],wv[200002],rank[200002],height[200002],bs[200002],tot;

int Is(int s,int e)
{
	while(s<e)
	{
		if(tar[s]==tar[e])
		{
			s++;
			e--;
		}
		else
			return 0;
	}
	return 1;

}

int cmp(int *ta,int s,int e,int len)
{
	if(ta[s]!=ta[e])
		return 0;
	if(ta[s+len]!=ta[e+len])
		return 0;
	return 1;

}
void Suffix_Array_Build()
{
	int *x=rank,*y=height,*t,i,j,m=127,p;
	for(i=0;i<m;i++)
		bs[i]=0;
	for(i=0;i<tot;i++)
		bs[x[i]=tar[i]]++;
	for(i=1;i<m;i++)
		bs[i]+=bs[i-1];
	for(i=tot-1;i>=0;i--)
		sa[--bs[x[i]]]=i;
	for(j=1,p=1;p<tot;j*=2,m=p)
	{
		for(p=0,i=tot-j;i<tot;i++)
			y[p++]=i;
		for(i=0;i<tot;i++)
			if(sa[i]>=j)
				y[p++]=sa[i]-j;
		for(i=0;i<tot;i++)
			wv[i]=x[y[i]];
		for(i=0;i<m;i++)
			bs[i]=0;
		for(i=0;i<tot;i++)
			bs[wv[i]]++;
		for(i=1;i<m;i++)
			bs[i]+=bs[i-1];
		for(i=tot-1;i>=0;i--)
			sa[--bs[wv[i]]]=y[i];
		t=x;
		x=y;
		y=t;
		for(p=1,x[sa[0]]=0,i=1;i<tot;i++)
		{
			if(cmp(y,sa[i],sa[i-1],j))
				x[sa[i]]=p-1;
			else
				x[sa[i]]=p++;
		}
	}
	return;
}

int main()
{
	int i,j,total;
	FILE *fin  = fopen ("hidden.in", "r");
    FILE *fout = fopen ("hidden.out", "w");
	fscanf(fin,"%d",&total);
	i=total;
	j=0;
	while(i>0)
	{
		fscanf(fin,"%s",tar+j);
		j+=72;
		i-=72;
	}
	for(i=0;i<total;i++)
	{
		tar[i+total]=tar[i];
	}
	tot=(total<<1)+1;
	tar[tot-1]='\0';
	
	Suffix_Array_Build();

	for(i=0;i<tot;i++)
	{
		if(tot-1-sa[i]>=total)
		{
			fprintf(fout,"%d\n",sa[i]%total);
			break;
		}
	}
	return 0;
}


