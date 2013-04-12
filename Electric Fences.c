/*
ID: sunheco1
LANG: C
TASK: fence3
*/
#include<stdio.h>
#include<math.h>

int Hs[152],He[152],Hv[152];

int Vs[152],Ve[152],Vh[152];

int toth,totv,total,xmin,ymin,xmax,ymax,xt,yt;

int mm[1024];

int main()
{
	int i,j,k,x1,x2,y1,y2;
	double tmp,now,min,nmin,nx,ny;
	FILE *fin  = fopen ("fence3.in", "r");
    FILE *fout = fopen ("fence3.out", "w");
	for(i=1;i<=1000;i++)
		mm[i]=i*i;
	xmin=ymin=1111;
	min=100000000;
	fscanf(fin,"%d",&total);
	for(i=1;i<=total;i++)
	{
		fscanf(fin,"%d %d %d %d",&x1,&y1,&x2,&y2);
		x1=(x1<<3)+(x1<<1);
		x2=(x2<<3)+(x2<<1);
		y1=(y1<<3)+(y1<<1);
		y2=(y2<<3)+(y2<<1);
		if(x1<xmin)
			xmin=x1;
		if(x1>xmax)
			xmax=x1;
		if(x2<xmin)
			xmin=x2;
		if(x2>xmax)
			xmax=x2;
		if(y1<ymin)
			ymin=y1;
		if(y1>ymax)
			ymax=y1;
		if(y2<ymin)
			ymin=y2;
		if(y2>ymax)
			ymax=y2;
		if(x1==x2)
		{
			totv++;
			Vh[totv]=x1;
			Vs[totv]=y1<y2?y1:y2;
			Ve[totv]=y1>y2?y1:y2;
		}
		else
		{
			toth++;
			Hv[toth]=y1;
			Hs[toth]=x1<x2?x1:x2;
			He[toth]=x1>x2?x1:x2;
		}
	}
	j=(xmin+xmax)>>1;
	for(i=xmin;i<=xmax;i++)
	{
		now=0;
		for(k=1;k<=toth;k++)
		{
			tmp=0;
			if(i<Hs[k])
				tmp+=mm[Hs[k]-i];
			if(i>He[k])
				tmp+=mm[i-He[k]];
			tmp+=Hv[k]-j>0?mm[Hv[k]-j]:mm[j-Hv[k]];
			now+=sqrt((double)tmp);
			if(now>min)
				break;
		}
		for(k=1;k<=totv;k++)
		{
			tmp=0;
			tmp+=Vh[k]-i>0?mm[Vh[k]-i]:mm[i-Vh[k]];
			if(j<Vs[k])
				tmp+=mm[Vs[k]-j];
			if(j>Ve[k])
				tmp+=mm[j-Ve[k]];
			now+=sqrt((double)tmp);
			if(now>min)
				break;
		}
		if(now<min)
		{
			min=now;
			xt=i;
			yt=j;
		}
	}
	for(j=((xmin+xmax)>>1)+1;j<=ymax;j++)
	{
		nmin=100000000;
		for(i=xmin;i<=xmax;i++)
		{
			now=0;		
			for(k=1;k<=toth;k++)
			{
				tmp=0;
				if(i<Hs[k])
					tmp+=mm[Hs[k]-i];
				if(i>He[k])
					tmp+=mm[i-He[k]];
				tmp+=Hv[k]-j>0?mm[Hv[k]-j]:mm[j-Hv[k]];
				now+=sqrt((double)tmp);
				if(now>nmin)
					break;
			}
			for(k=1;k<=totv;k++)
			{
				tmp=0;
				tmp+=Vh[k]-i>0?mm[Vh[k]-i]:mm[i-Vh[k]];
				if(j<Vs[k])
					tmp+=mm[Vs[k]-j];
				if(j>Ve[k])
					tmp+=mm[j-Ve[k]];
				now+=sqrt((double)tmp);
				if(now>nmin)
					break;
			}
			if(now<nmin)
			{
				nmin=now;
				nx=i;
				ny=j;
			}
		}
		if(nmin>min)
			break;
		else
		{
			min=nmin;
			xt=nx;
			yt=ny;
		}
	}
	for(j=((xmin+xmax)>>1)-1;j>=ymin;j++)
	{
		nmin=100000000;
		for(i=xmin;i<=xmax;i++)
		{
			now=0;
			for(k=1;k<=toth;k++)
			{
				tmp=0;
				if(i<Hs[k])
					tmp+=mm[Hs[k]-i];
				if(i>He[k])
					tmp+=mm[i-He[k]];
				tmp+=Hv[k]-j>0?mm[Hv[k]-j]:mm[j-Hv[k]];
				now+=sqrt((double)tmp);
				if(now>nmin)
					break;
			}
			for(k=1;k<=totv;k++)
			{
				tmp=0;
				tmp+=Vh[k]-i>0?mm[Vh[k]-i]:mm[i-Vh[k]];
				if(j<Vs[k])
					tmp+=mm[Vs[k]-j];
				if(j>Ve[k])
					tmp+=mm[j-Ve[k]];
				now+=sqrt((double)tmp);
				if(now>nmin)
					break;
			}
			if(now<nmin)
			{
				nmin=now;
				nx=i;
				ny=j;
			}
		}
		if(nmin>min)
			break;
		else
		{
			min=nmin;
			xt=nx;
			yt=ny;
		}
	}
	fprintf(fout,"%0.1lf %0.1lf %0.1lf\n",(double)xt/(double)10,(double)yt/(double)10,(double)min/(double)10);
	return 0;
}
