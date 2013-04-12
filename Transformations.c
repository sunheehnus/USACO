/*
ID: sunheco1
LANG: C
TASK: transform
*/
#include<stdio.h>

char ori[11][11],tar[11][11],map1[11][11],map2[11][11],map3[11][11],map4[11][11],map5[11][11],map6[11][11],map7[11][11],map8[11][11];

char temp[11];

int n;

int Equal(char (*a)[11],char (*b)[11])
{
	char *tar1,*tar2;
	int i,j;
	for(i=1;i<=n;i++)
	{
		tar1=(char *)(a+i);
		tar2=(char *)(b+i);
		for(j=1;j<=n;j++)
		{
			if(tar1[j]!=tar2[j])
				return 0;
		}
	}
	return 1;
}

int main()
{
	int total,i,j,k,l;
	FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%s",&ori[i][1]);
	}
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%s",&tar[i][1]);
	}
	for(i=1,k=n;i<=n;i++,k--)
	{
		for(j=1;j<=n;j++)
			map1[j][k]=ori[i][j];
	}
	if(Equal(map1,tar))
	{
		fprintf(fout,"1\n");
		return 0;
	}
	for(i=1,k=n;i<=n;i++,k--)
	{
		for(j=1,l=n;j<=n;j++,l--)
			map2[k][l]=ori[i][j];
	}
	if(Equal(map2,tar))
	{
		fprintf(fout,"2\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1,k=n;j<=n;j++,k--)
			map3[k][i]=ori[i][j];
	}
	if(Equal(map3,tar))
	{
		fprintf(fout,"3\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1,k=n;j<=n;j++,k--)
			map4[i][k]=ori[i][j];
	}
	if(Equal(map4,tar))
	{
		fprintf(fout,"4\n");
		return 0;
	}
	for(i=1,k=n;i<=n;i++,k--)
	{
		for(j=1;j<=n;j++)
			map5[j][k]=map4[i][j];
	}
	if(Equal(map5,tar))
	{
		fprintf(fout,"5\n");
		return 0;
	}
	for(i=1,k=n;i<=n;i++,k--)
	{
		for(j=1,l=n;j<=n;j++,l--)
			map6[k][l]=map4[i][j];
	}
	if(Equal(map6,tar))
	{
		fprintf(fout,"5\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1,k=n;j<=n;j++,k--)
			map7[k][i]=map4[i][j];
	}
	if(Equal(map7,tar))
	{
		fprintf(fout,"5\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			map8[i][j]=ori[i][j];
	}
	if(Equal(map8,tar))
	{
		fprintf(fout,"6\n");
		return 0;
	}
	fprintf(fout,"7\n");
	return 0;
}