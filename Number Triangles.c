/*
ID: sunheco1
LANG: C
TASK: numtri
*/
#include <stdio.h>
   
int total;
int tri[500501],map[500501];

int main()
{
	int tot1,tot2,i,j,max,tot;
	FILE *fin  = fopen ("numtri.in", "r");
    FILE *fout = fopen ("numtri.out", "w");
	fscanf(fin,"%d",&total);
	tot=(total+1)*total>>1;
	for(i=1;i<=tot;i++)
		fscanf(fin,"%d",tri+i);
	for(i=1;i<total;i++)
	{
		tot1=(1+i)*i>>1;
		tot2=(i-1)*i>>1;
		for(j=1;j<=i;j++)
		{
			if(map[tot1+j]<map[tot2+j]+tri[tot2+j])
				map[tot1+j]=map[tot2+j]+tri[tot2+j];

			if(map[tot1+j+1]<map[tot2+j]+tri[tot2+j])
				map[tot1+j+1]=map[tot2+j]+tri[tot2+j];
		}
	}		
	for(max=0,tot=(total+1)*total>>1,i=(i-1)*i>>1;i<=tot;i++)
	{
		if(map[i]+tri[i]>max)
			max=map[i]+tri[i];
	}
	fprintf(fout,"%d\n",max);
	return 0;
}