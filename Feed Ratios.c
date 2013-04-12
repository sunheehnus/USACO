/*
ID: sunheco1
LANG: C
TASK: ratios
*/
#include<stdio.h>

struct Node{int x1,x2,x3,tar1,tar2,tar3;}node[131072];

char map[100][100][100];

int inc[4][4];

int main()
{
	int tar1,tar2,tar3,x1,x2,x3,s,e,tot;
	struct Node temp;
	FILE *fin  = fopen ("ratios.in", "r");
    FILE *fout = fopen ("ratios.out", "w");
	fscanf(fin,"%d %d %d",&tar1,&tar2,&tar3);
	fscanf(fin,"%d %d %d",&inc[1][1],&inc[1][2],&inc[1][3]);
	fscanf(fin,"%d %d %d",&inc[2][1],&inc[2][2],&inc[2][3]);
	fscanf(fin,"%d %d %d",&inc[3][1],&inc[3][2],&inc[3][3]);
	tot=0;
	s=0;
	e=0;
	map[0][0][0]=1;
	while(tot<1000000)
	{
		s=(s+1)&131071;
		tot++;
		temp=node[s];
		x1=temp.x1;
		x2=temp.x2;
		x3=temp.x3;
		if(!(tar1==0&&inc[1][1]!=0||tar2==0&&inc[1][2]!=0||tar3==0&&inc[1][3]!=0)&&x1+1<100&&!map[x1+1][x2][x3])
		{
			e=(e+1)&131071;
			node[e].x1=x1+1;
			node[e].x2=x2;
			node[e].x3=x3;
			node[e].tar1=temp.tar1+inc[1][1];
			node[e].tar2=temp.tar2+inc[1][2];
			node[e].tar3=temp.tar3+inc[1][3];
			map[x1+1][x2][x3]=1;
			if((tar1==0||node[e].tar1%tar1==0)&&(tar2==0||node[e].tar2%tar2==0)&&(tar3==0||node[e].tar3%tar3==0)&&(tar1==0||tar2==0||node[e].tar1/tar1==node[e].tar2/tar2)&&(tar1==0||tar3==0||node[e].tar1/tar1==node[e].tar3/tar3)) 
				break;
		}
		if(!(tar1==0&&inc[2][1]!=0||tar2==0&&inc[2][2]!=0||tar3==0&&inc[2][3]!=0)&&x2+1<100&&!map[x1][x2+1][x3])
		{
			e=(e+1)&131071;
			node[e].x1=x1;
			node[e].x2=x2+1;
			node[e].x3=x3;
			node[e].tar1=temp.tar1+inc[2][1];
			node[e].tar2=temp.tar2+inc[2][2];
			node[e].tar3=temp.tar3+inc[2][3];
			map[x1][x2+1][x3]=1;
			if((tar1==0||node[e].tar1%tar1==0)&&(tar2==0||node[e].tar2%tar2==0)&&(tar3==0||node[e].tar3%tar3==0)&&(tar1==0||tar2==0||node[e].tar1/tar1==node[e].tar2/tar2)&&(tar1==0||tar3==0||node[e].tar1/tar1==node[e].tar3/tar3))
				break;
		}
		if(!(tar1==0&&inc[3][1]!=0||tar2==0&&inc[3][2]!=0||tar3==0&&inc[3][3]!=0)&&x3+1<100&&!map[x1][x2][x3+1])
		{
			e=(e+1)&131071;
			node[e].x1=x1;
			node[e].x2=x2;
			node[e].x3=x3+1;
			node[e].tar1=temp.tar1+inc[3][1];
			node[e].tar2=temp.tar2+inc[3][2];
			node[e].tar3=temp.tar3+inc[3][3];
			map[x1][x2][x3+1]=1;
			if((tar1==0||node[e].tar1%tar1==0)&&(tar2==0||node[e].tar2%tar2==0)&&(tar3==0||node[e].tar3%tar3==0)&&(tar1==0||tar2==0||node[e].tar1/tar1==node[e].tar2/tar2)&&(tar1==0||tar3==0||node[e].tar1/tar1==node[e].tar3/tar3))
				break;
		}
	}
	if(tot==1000000)
		fprintf(fout,"NONE\n");
	else
		fprintf(fout,"%d %d %d %d\n",node[e].x1,node[e].x2,node[e].x3,node[e].tar1/tar1);
	return 0;
}