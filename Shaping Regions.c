/*
ID: sunheco1
LANG: C
TASK: rect1
*/
#include<stdio.h>

struct rec{int llx,lly,urx,ury,color,exist;};

struct rec region[6666];

int llx,lly,urx,ury,color,tot,cur;

int result[3333];

void insert()
{
	int i,j;
	for(i=1;i<=tot;i++)
	{
		if(region[i].llx>urx||region[i].urx<llx||region[i].ury<lly||region[i].lly>ury)
			continue;
		if(region[i].llx<llx)
		{
			region[++cur].llx=region[i].llx;
			region[cur].lly=region[i].lly;
			region[cur].urx=llx-1;
			region[cur].ury=region[i].ury;
			region[cur].exist=1;
			region[cur].color=region[i].color;
		}
		if(region[i].lly<lly&&region[i].ury>=lly)
		{
			region[++cur].llx=region[i].llx>llx?region[i].llx:llx;
			region[cur].lly=region[i].lly;
			region[cur].urx=region[i].urx>urx?urx:region[i].urx;
			region[cur].ury=lly-1;
			region[cur].exist=1;
			region[cur].color=region[i].color;
		}
		if(region[i].ury>ury&&region[i].lly<=ury)
		{
			region[++cur].llx=region[i].llx>llx?region[i].llx:llx;
			region[cur].lly=ury+1;
			region[cur].urx=region[i].urx>urx?urx:region[i].urx;
			region[cur].ury=region[i].ury;
			region[cur].exist=1;
			region[cur].color=region[i].color;
		}
		if(region[i].urx>urx)
		{
			region[++cur].llx=urx+1;
			region[cur].lly=region[i].lly;
			region[cur].urx=region[i].urx;
			region[cur].ury=region[i].ury;
			region[cur].exist=1;
			region[cur].color=region[i].color;
		}
		region[i].exist=0;
	}
	region[++cur].llx=llx;
	region[cur].lly=lly;
	region[cur].urx=urx;
	region[cur].ury=ury;
	region[cur].exist=1;
	region[cur].color=color;
	for(i=1,j=1;i<=cur;i++)
	{
		if(region[i].exist==0)
			continue;
		region[j++]=region[i];
	}
	tot=j-1;
}

int main()
{
	int A,B,N,i;
	FILE *fin  = fopen ("rect1.in", "r");
    FILE *fout = fopen ("rect1.out", "w");
	fscanf(fin,"%d %d",&A,&B);
	fscanf(fin,"%d",&N);
	region[1].llx=region[1].lly=1;
	region[1].urx=A;
	region[1].ury=B;
	region[1].exist=1;
	region[1].color=1;
	tot=1;
	for(i=1;i<=N;i++)
	{
		fscanf(fin,"%d %d %d %d %d",&llx,&lly,&urx,&ury,&color);
		llx++;
		lly++;
		cur=tot;
		insert();
	}
	for(i=1;i<=tot;i++)
	{
		result[region[i].color]+=(region[i].urx-region[i].llx+1)*(region[i].ury-region[i].lly+1);
	}
	for(i=1;i<=2500;i++)
	{
		if(result[i])
		{
			fprintf(fout,"%d %d\n",i,result[i]);
		}
	}
	return 0;
}