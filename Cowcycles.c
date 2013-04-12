/*
ID: sunheco1
LANG: C
TASK: cowcycle
*/
#include<stdio.h>

int F,R,F1,F2,R1,R2,FF[256],RR[256],cnt,OF[256],OR[256];

double map[128],av[128],min;

void quicksort(int s,int e)
{
	int i,j,mid;
	double temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(s+e)>>1;
		temp=map[mid];
		map[mid]=map[i];
		while(i<j)
		{
			while(i<j&&temp<=map[j])
				j--;
			map[i]=map[j];
			while(i<j&&temp>=map[i])
				i++;
			map[j]=map[i];
		}
		map[i]=temp;
		quicksort(s,i-1);
		quicksort(i+1,e);
	}
}

int pop(unsigned x)
{
	x=x-((x>>1)&0x55555555);
	x=(x&0x33333333)+((x>>2)&0x33333333);
	x=(x+((x>>4)&0x0f0f0f0f))&0x0f0f0f0f;
	x=x+(x>>8);
	return ((x+(x>>16))&0x3f);
}

int next(int x)
{
	int tmp;
	tmp=x&(-x);
	return ((1<<(pop(x^(tmp+x))-2))-1)|(x+tmp);
}

void Deal(int s1,int e1,int s2,int e2)
{
	int tar1,tar2,zs1,zs2,tmp1,tmp2,i,j;
	double tmp;
	FF[1]=s1;
	FF[F]=e1;
	RR[1]=s2;
	RR[R]=e2;
	zs1=e1-s1+1-F;
	zs2=e2-s2+1-R;
	for(tar1=(((-1)<<(e1-s1-1)))|((1<<(F-2))-1);pop(~tar1)==zs1;tar1=next(tar1))
	{
		for(tar2=(((-1)<<(e2-s2-1)))|((1<<(R-2))-1);pop(~tar2)==zs2;tar2=next(tar2))
		{
			tmp1=tar1;
			tmp2=tar2;
			for(i=1,j=2;j<F;i++)
			{
				if(tmp1&1)
				{
					FF[j]=s1+i;
					j++;
				}
				tmp1=tmp1>>1;
			}
			for(i=1,j=2;j<R;i++)
			{
				if(tmp2&1)
				{
					RR[j]=s2+i;
					j++;
				}
				tmp2=tmp2>>1;
			}
			for(i=1,cnt=0;i<=F;i++)
			{
				for(j=1;j<=R;j++)
				{
					map[++cnt]=(double)(((double)FF[i])/((double)RR[j]));
				}
			}
			quicksort(1,cnt);
			av[cnt]=av[cnt+1]=0;
			for(i=1;i<cnt;i++)
			{
				av[i]=map[i+1]-map[i];
				av[cnt]+=av[i];
			}
			av[cnt]/=(cnt-1);
			for(i=1;i<cnt;i++)
			{
				tmp=av[i]-av[cnt];
				av[i]=tmp*tmp;
				av[cnt+1]+=av[i];
			}
			av[cnt+1]/=(cnt-1);
			if(av[cnt+1]<min)
			{
				min=av[cnt+1];
				for(i=1;i<=R;i++)
				{
					OR[i]=RR[i];
				}
				for(i=1;i<=F;i++)
				{
					OF[i]=FF[i];
				}
			}
		}
	}
}

int main()
{
	int s1,s2,e1,e2,tmp,i;
	FILE *fin  = fopen ("cowcycle.in", "r");
    FILE *fout = fopen ("cowcycle.out", "w");
	min=100000000;
	fscanf(fin,"%d %d %d %d %d %d",&F,&R,&F1,&F2,&R1,&R2);
	for(s1=F1;s1<=F2;s1++)
	{
		for(e1=s1+F-1;e1<=F2;e1++)
		{
			for(s2=R1;s2<=R2;s2++)
			{
				for(e2=s2+R-1;e2<=R2;e2++)
				{
					tmp=(e1*e2)/(s1*s2);
					if(tmp>=3)
					{
						Deal(s1,e1,s2,e2);
					}
				}
			}
		}
	}
	for(i=1;i<F;i++)
	{
		fprintf(fout,"%d ",OF[i]);
	}
	fprintf(fout,"%d\n",OF[i]);
	for(i=1;i<R;i++)
	{
		fprintf(fout,"%d ",OR[i]);
	}
	fprintf(fout,"%d\n",OR[i]);
	return 0;
}