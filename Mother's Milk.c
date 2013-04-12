/*
ID: sunheco1
LANG: C
TASK: milk3
*/
#include<stdio.h>

int a[10000],b[10000],c[10000],v[10000];

int a1,b1,c1;

int cur;

int find(int a2,int b2,int c2)
{
	int i;
	for(i=1;i<=cur;i++)
	{
		if(a[i]==a2&&b[i]==b2&&c[i]==c2)
			return 1;
	}
	return 0;
}

void insert(int a2,int b2,int c2)
{
	cur++;
	a[cur]=a2;
	b[cur]=b2;
	c[cur]=c2;
}

void search(int a2,int b2,int c2)
{
	if(find(a2,b2,c2))
		return;
	insert(a2,b2,c2);
	search(a2,(b2+c2)>b1?b1:(c2+b2),(b2+c2)>b1?(c2+b2-b1):0);
	search((a2+c2)>a1?a1:(c2+a2),b2,(a2+c2)>a1?(c2+a2-a1):0);
	search(a2,(b2+c2)>c1?(c2+b2-c1):0,(b2+c2)>c1?c1:(b2+c2));
	search((a2+b2)>a1?a1:(a2+b2),(a2+b2)>a1?(b2+a2-a1):0,c2);
	search((a2+b2)>b1?(a2+b2-b1):0,(a2+b2)>b1?b1:(a2+b2),c2);
	search((a2+c2)>c1?(a2+c2-c1):0,b2,(a2+c2)>c1?c1:(a2+c2));
}

int main()
{
	int i;
	FILE *fin  = fopen ("milk3.in", "r");
    FILE *fout = fopen ("milk3.out", "w");
	fscanf(fin,"%d %d %d",&a1,&b1,&c1);
	search(0,0,c1);
	for(i=1;i<=cur;i++)
	{
		if(a[i]==0)
			v[c[i]]=1;
	}
	for(i=0;i<=c1;i++)
	{
		if(v[i])
		{
			fprintf(fout,"%d",i);
			break;
		}
	}
	for(i++;i<=c1;i++)
	{
		if(v[i])
			fprintf(fout," %d",i);
	}
	fprintf(fout,"\n");
	return 0;
}