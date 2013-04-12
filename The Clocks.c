/*
ID: sunheco1
LANG: C
TASK: clocks
*/
#include<stdio.h>

int clocks[10],step[100],flag,bound;

int clock[10][10]={ 
	0,0,0,0,0,0,0,0,0,0,
	4,1,2,4,5,0,0,0,0,0,
	3,1,2,3,0,0,0,0,0,0,
	4,2,3,5,6,0,0,0,0,0,
	3,1,4,7,0,0,0,0,0,0,
	5,2,4,5,6,8,0,0,0,0,
	3,3,6,9,0,0,0,0,0,0,
	4,4,5,7,8,0,0,0,0,0,
	3,7,8,9,0,0,0,0,0,0,
	4,5,6,8,9,0,0,0,0,0,};

void pfc(int i)
{
	int j;
	for(j=1;j<=clock[i][0];j++)
	{
		if(clocks[clock[i][j]]==12)
			clocks[clock[i][j]]=3;
		else
			clocks[clock[i][j]]+=3;
	}
}
void pbc(int i)
{
	int j;
	for(j=1;j<=clock[i][0];j++)
	{
		if(clocks[clock[i][j]]==3)
			clocks[clock[i][j]]=12;
		else
			clocks[clock[i][j]]-=3;
	}
}
int Is()
{
	return clocks[1]+clocks[2]+clocks[3]+clocks[4]+clocks[5]+clocks[6]+clocks[7]+clocks[8]+clocks[9]==108;
}
void find(int now,int i,int cur)
{
	int temp=i;
	if(now>bound)
		return;
	if(cur==4)
	{
		i++;
	}
	for(;i<=9;i++)
	{
		if(!flag)
		{
			step[now]=i;
			pfc(i);
			flag=Is();
			find(now+1,i,temp==i?(cur+1):2);
			pbc(i);
		}
	}
}
int main()
{
	int i;
	FILE *fin  = fopen ("clocks.in", "r");
    FILE *fout = fopen ("clocks.out", "w");
	for(i=1;i<=9;i++)
		fscanf(fin,"%d",clocks+i);
	for(bound=1;!flag;bound++)
		find(1,1,1);
	bound--;
	fprintf(fout,"%d",step[1]);
	for(i=2;i<=bound;i++)
		fprintf(fout," %d",step[i]);
	fprintf(fout,"\n");
	return 0;
}
//9 9 12 6 6 6 6 3 6