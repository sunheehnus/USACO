/*
ID: sunheco1
LANG: C
TASK: lamps
*/
#include<stdio.h>

int N,C,tot,ft,ont,offt,min;

int lamps[111][111],on[111],off[111],sort[100];

void Find(int i)
{
	int j;
	tot++;
	for(j=1;j<=N;j++)
		lamps[tot][j]=1;
	if(i&1)
	{
		for(j=1;j<=N;j++)
			lamps[tot][j]^=1;
	}
	if(i&2)
	{
		for(j=1;j<=N;j+=2)
			lamps[tot][j]^=1;
	}
	if(i&4)
	{
		for(j=2;j<=N;j+=2)
			lamps[tot][j]^=1;
	}
	if(i&8)
	{
		for(j=1;j<=N;j+=3)
			lamps[tot][j]^=1;
	}

}

void Deal(int tar)
{
	int i;
	for(i=0;i<16;i++)
	{
		if((i>>3)+((i>>2)&1)+((i>>1)&1)+(i&1)==tar)
			Find(i);
	}
}
int Judge(int i)
{
	int *lamp=&lamps[i][0],j;
	for(j=1;j<=ont;j++)
	{
		if(lamp[on[j]]==0)
			return 0;
	}
	for(j=1;j<=offt;j++)
	{
		if(lamp[off[j]]==1)
			return 0;
	}
	return 1;
}
int compare(int i,int j)
{
	int k;
	for(k=1;k<=N;k++)
	{
		if(lamps[i][k]>lamps[j][k])
			return 1;
		if(lamps[i][k]<lamps[j][k])
			return 0;
	}
}

int Min()
{
	int i;
	for(i=1;i<=ft;i++)
	{
		if(min==-1&&lamps[sort[i]][0]==0)
		{
			min=sort[i];
			continue;
		}
		if(min==-1)
			continue;
		if(lamps[sort[i]][0]==0)
		{
			if(compare(min,sort[i]))
				min=sort[i];
		}
	}
	if(min==-1)
		return 0;
	lamps[min][0]=1;
	return 1;
}
int main()
{
	int i;
	FILE *fin  = fopen ("lamps.in", "r");
    FILE *fout = fopen ("lamps.out", "w");
	fscanf(fin,"%d %d",&N,&C);
	fscanf(fin,"%d",on+(++ont));
	while(on[ont]!=-1)
	{
		fscanf(fin,"%d",on+(++ont));
	}
	ont--;
	fscanf(fin,"%d",off+(++offt));
	while(off[offt]!=-1)
	{
		fscanf(fin,"%d",off+(++offt));
	}
	offt--;
	if(C&1)
	{
		switch(C)
		{
		default:
			Deal(3);
		case 1:
			Deal(1);
			break;
		}
	}
	else
	{
		switch(C)
		{
		default:
			Deal(4);
		case 2:
			Deal(2);
		case 0:
			Deal(0);
		}
	}
	for(i=1;i<=tot;i++)
	{
		if(Judge(i))
		{
			ft++;
			sort[ft]=i;
		}
	}

	if(ft==0)
		fprintf(fout,"IMPOSSIBLE\n");
	else
	{
		while(1)
		{
			min=-1;
			if(Min()==0)
				break;
			for(i=1;i<=N;i++)
				fprintf(fout,"%d",lamps[min][i]);
			fprintf(fout,"\n");
		}
	}
	return 0;
}
