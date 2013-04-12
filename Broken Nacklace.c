/*
ID: sunheco1
LANG: C
TASK: beads
*/
#include<stdio.h>
char nacklace[1000],co1,co2;

int main()
{
	int n,i,j,k,max,temp1,temp2;
	FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");
	fscanf(fin,"%d",&n);
	fscanf(fin,"%s",nacklace);
	for(j=n,i=0;i<n;i++,j++)
		nacklace[j]=nacklace[i];
	nacklace[j]='\0';
	n=n<<1;
	max=0;
	for(i=0;i<n;i++)
	{
		temp1=temp2=0;
		j=i;
		k=i+1;
		co1=nacklace[j];
		co2=nacklace[k];
		while(j>=0)
		{
			if(co1!='w'&&nacklace[j]!=co1&&nacklace[j]!='w')
				break;
			if(co1=='w')
				co1=nacklace[j];
			temp1++;
			j--;
		}
		while(k<n)
		{
			if(co2!='w'&&nacklace[k]!=co2&&nacklace[k]!='w')
				break;
			if(co2=='w')
				co2=nacklace[k];
			k++;
			temp2++;
		}
		if(temp1+temp2>max)
			max=temp1+temp2;
	}
	if(max>n>>1)
		max=n>>1;
	fprintf(fout,"%d\n",max);
	return 0;
}