/*
ID: sunheco1
LANG: C
TASK: picture
*/
#include<stdio.h>

char x[20008],y[20008];

struct XLine{int s,e,y;char is;} xline[10000];
struct YLine{int s,e,x;char is;} yline[10000];

int sum;

void Dealx(int now)
{
	int i;
	if(xline[now].is==0)
	{
		for(i=xline[now].s;i<xline[now].e;i++)
		{
			x[i]--;
			if(x[i]==0)
			{
				sum++;
			}
		}
	}
	else
	{
		for(i=xline[now].s;i<xline[now].e;i++)
		{
			x[i]++;
			if(x[i]==1)
			{
				sum++;
			}
		}
	}
}

void Dealy(int now)
{
	int i;
	if(yline[now].is==0)
	{
		for(i=yline[now].s;i<yline[now].e;i++)
		{
			y[i]--;
			if(y[i]==0)
			{
				sum++;
			}
		}
	}
	else
	{
		for(i=yline[now].s;i<yline[now].e;i++)
		{
			y[i]++;
			if(y[i]==1)
			{
				sum++;
			}
		}
	}
}

void quicksortx(int s,int e)
{
	int i,j,mid;
	struct XLine tmp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(i+j)>>1;
		tmp=xline[mid];
		xline[mid]=xline[i];
		while(i<j)
		{
			while(i<j&&(xline[j].y>tmp.y||(xline[j].y==tmp.y&&(tmp.is==1||xline[j].is==0))))
				j--;
			xline[i]=xline[j];
			while(i<j&&(xline[i].y<tmp.y||(xline[i].y==tmp.y&&(tmp.is==0||xline[j].is==1))))
				i++;
			xline[j]=xline[i];
		}
		xline[i]=tmp;
		quicksortx(s,i-1);
		quicksortx(i+1,e);
	}
}

void quicksorty(int s,int e)
{
	int i,j,mid;
	struct YLine tmp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(i+j)>>1;
		tmp=yline[mid];
		yline[mid]=yline[i];
		while(i<j)
		{
			while(i<j&&(yline[j].x>tmp.x||(yline[j].x==tmp.x&&(tmp.is==1||yline[j].is==0))))
				j--;
			yline[i]=yline[j];
			while(i<j&&(yline[i].x<tmp.x||(yline[i].x==tmp.x&&(tmp.is==0||yline[j].is==1))))
				i++;
			yline[j]=yline[i];
		}
		yline[i]=tmp;
		quicksorty(s,i-1);
		quicksorty(i+1,e);
	}
}

int main()
{
	int i,now,lx,ly,rx,uy,total;
	FILE *fin  = fopen ("picture.in", "r");
    FILE *fout = fopen ("picture.out", "w");
	fscanf(fin,"%d",&total);
	for(i=1,now=1;i<=total;i++)
	{
		fscanf(fin,"%d %d %d %d",&lx,&ly,&rx,&uy);
		lx+=10000;
		ly+=10000;
		rx+=10000;
		uy+=10000;
		xline[now].s=lx;
		xline[now].e=rx;
		xline[now].y=ly;
		xline[now].is=1;
		yline[now].s=ly;
		yline[now].e=uy;
		yline[now].x=lx;
		yline[now].is=1;
		now++;
		xline[now].s=lx;
		xline[now].e=rx;
		xline[now].y=uy;
		xline[now].is=0;
		yline[now].s=ly;
		yline[now].e=uy;
		yline[now].x=rx;
		yline[now].is=0;
		now++;
	}
	quicksortx(1,total<<1);
	quicksorty(1,total<<1);
	total=total<<1;
	for(i=1;i<=total;i++)
	{
		Dealx(i);
		Dealy(i);
	}
	fprintf(fout,"%d\n",sum);
	return 0;
}
