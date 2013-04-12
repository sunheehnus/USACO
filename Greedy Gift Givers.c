/*
ID: sunheco1
LANG: C
TASK: gift1 
*/
#include <stdio.h>


char name[20][20],temp[20];
int in[20],ini[20],total,i,j,k,init,left,give,find;

int Equal(char *a,char *b)
{
	while(*a==*b&&*a!='\0')
	{
		a++;
		b++;
	}
	if(*a==*b)
		return 1;
	return 0;
}

int Search(char *a)
{
	int ti;
	for(ti=0;ti<total;ti++)
		if(Equal(a,&name[ti][0]))
			return ti;
}

int main() 
{
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");

	fscanf(fin,"%d",&total);
	for(i=0;i<total;i++)
	{
		fscanf(fin,"%s",(char *)&name[i][0]);
	}
	for(i=0;i<total;i++)
	{
		fscanf(fin,"%s",temp);
		fscanf(fin,"%d",&init);
		fscanf(fin,"%d",&j);
		find=Search(temp);
		ini[find]=init;
		if(j==0)
		{
			in[find]+=init;
			continue;
		}
		left=init%j;
		give=init/j;
		in[find]+=left;
		for(k=0;k<j;k++)
		{
			fscanf(fin,"%s",temp);
			find=Search(temp);
			in[find]+=give;
		}
	}
	for(i=0;i<total;i++)
	{
		fprintf(fout,"%s %d\n",&name[i][0],in[i]-ini[i]);
	}
    return 0;
}
