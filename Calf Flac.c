/*
ID: sunheco1
LANG: C
TASK: calfflac
*/
#include <stdio.h>
int max,start;
char a[30001],tar[40044];
int sa[40044],wv[40044],rank[40044],height[40044],bs[40044],tot,point;

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
void Height_Array_Build()
{
	int i,j,k;
	for(i=0;i<tot;i++)
		rank[sa[i]]=i;
	for(i=0,k=0;i<tot-1;height[rank[i++]]=k)
	{
		if(k>0)
			k--;
		j=sa[rank[i]-1];
		while(tar[j+k]==tar[i+k])
			k++;
	}
}
int main()
{
	int i,j,mi,ma;
	char *cc=a;
	FILE *fin  = fopen ("calfflac.in", "r");
    FILE *fout = fopen ("calfflac.out", "w+");
	while((fgets(cc,100,fin)!=0))
	{
		while(*cc)
		{
			cc++;
		}
	}
	for(i=0,j=0;a[i]!='\0';i++)
	{
		if(!(a[i]>='A'&&a[i]<='Z'||a[i]>='a'&&a[i]<='z'))
			continue;
		tar[j]=a[i]&0xdf;
		j++;
	}
	point=j;
	tar[j]='Z'+1;
	tot=point+j+2;
	tar[tot-1]='\0';
	for(i=0,j=tot-2;i<point;i++,j--)
	{
		tar[j]=tar[i];
	}
	Suffix_Array_Build();
	Height_Array_Build();
	max=1;
	start=1;
	for(i=1;i<tot;i++)
	{
		if(height[i]>max)
		{
			if(sa[i]>sa[i-1])
			{
				mi=sa[i-1];
				ma=sa[i];
			}
			else
			{
				mi=sa[i];
				ma=sa[i-1];
			}
			if(mi<point&&ma>point&&Is(mi,mi+height[i]-1))
			{
				max=height[i];
				start=mi;
			}
		}
		else if(height[i]==max)
		{
			if(sa[i]>sa[i-1])
			{
				mi=sa[i-1];
				ma=sa[i];
			}
			else
			{
				mi=sa[i];
				ma=sa[i-1];
			}
			if(mi<point&&ma>point&&mi<start&&Is(mi,mi+height[i]-1))
				start=mi;
		}
	}
	fprintf(fout,"%d\n",max);
	i=0;
	j=0;
	while(j<start)
	{
		if(a[i]>='A'&&a[i]<='Z'||a[i]>='a'&&a[i]<='z')
			j++;
		i++;
	}
	while(!(a[i]>='A'&&a[i]<='Z'||a[i]>='a'&&a[i]<='z'))
		i++;
	while(max>0)
	{
		fprintf(fout,"%c",a[i]);
		if(a[i]>='A'&&a[i]<='Z'||a[i]>='a'&&a[i]<='z')
			max--;
		i++;
	}
	fprintf(fout,"\n");
	return 0;
}
