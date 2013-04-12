/*
ID: sunheco1
LANG: C
TASK: fc
*/
#include<stdio.h>

#include<math.h>

struct Node{double x,y,radian;}node[10008];

double xs,ys,result;

int total,start,now;

int route[10008];

double radian[10008];

void quicksort(int s,int e)
{
	int i,j,mid;
	struct Node temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(s+e)>>1;
		temp=node[mid];
		node[mid]=node[i];
		while(i<j)
		{
			while(i<j&&node[j].radian>=temp.radian)
				j--;
			node[i]=node[j];
			while(i<j&&node[i].radian<=temp.radian)
				i++;
			node[j]=node[i];
		}
		node[i]=temp;
		quicksort(s,i-1);
		quicksort(i+1,e);
	}
}

void Judge(int i)
{
	double tmp;
	for(;now>0;)
	{
		tmp=atan2(node[i].y-node[route[now]].y,node[i].x-node[route[now]].x);
		tmp=tmp>=0?tmp:2*3.1415926535897932384626433832795+tmp;
		if(tmp<radian[now])
			now--;
		else
		{
			radian[++now]=tmp;
			route[now]=i;
			return;
		}
	}
	tmp=atan2(node[i].y-ys,node[i].x-xs);
	tmp=tmp>=0?tmp:2*3.1415926535897932384626433832795+tmp;
	radian[++now]=tmp;
	route[now]=i;
}

int main()
{
	int i;
	FILE *fin  = fopen ("fc.in", "r");
    FILE *fout = fopen ("fc.out", "w");
	fscanf(fin,"%d",&total);
	for(i=1,xs=1111111,ys=1111111;i<=total;i++)
	{
		fscanf(fin,"%lf %lf",&node[i].x,&node[i].y);
		if(node[i].y<ys||(node[i].y==ys&&node[i].x<xs))
		{
			xs=node[i].x;
			ys=node[i].y;
			start=i;
		}
	}
	for(i=1;i<start;i++)
	{
		node[i].radian=atan2(node[i].y-ys,node[i].x-xs);
		node[i].radian=node[i].radian>=0?node[i].radian:2*3.1415926535897932384626433832795+node[i].radian;
	}
	for(i=start;i<total;i++)
	{
		node[i]=node[i+1];
		node[i].radian=atan2(node[i+1].y-ys,node[i+1].x-xs);
		node[i].radian=node[i].radian>=0?node[i].radian:2*3.1415926535897932384626433832795+node[i].radian;
	}
	node[total].x=xs;
	node[total].y=ys;
	quicksort(1,total-1);
	for(i=1;i<=total;i++)
	{
		Judge(i);
	}
	for(i=2;i<=now;i++)
	{
		result+=sqrt((node[route[i]].x-node[route[i-1]].x)*(node[route[i]].x-node[route[i-1]].x)+(node[route[i]].y-node[route[i-1]].y)*(node[route[i]].y-node[route[i-1]].y));
	}
	result+=sqrt((node[route[1]].x-xs)*(node[route[1]].x-xs)+(node[route[1]].y-ys)*(node[route[1]].y-ys));
	fprintf(fout,"%.2lf\n",result);
	return 0;
}