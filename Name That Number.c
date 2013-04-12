/*
ID: sunheco1
LANG: C
TASK: namenum
*/
#include<stdio.h>

char tar1[5555][32],tar2[5555][32],temp[32];

void a2i(char *a,char *b)
{
	while(*a!='\0')
	{
		if(*a=='Q'||*a=='Z')
			*b='0';
		else if(*a>='A'&&*a<='C')
			*b='2';
		else if(*a>='D'&&*a<='F')
			*b='3';
		else if(*a>='G'&&*a<='I')
			*b='4';
		else if(*a>='J'&&*a<='L')
			*b='5';
		else if(*a>='M'&&*a<='O')
			*b='6';
		else if(*a>='P'&&*a<='S')
			*b='7';
		else if(*a>='T'&&*a<='V')
			*b='8';
		else if(*a>='W'&&*a<='Y')
			*b='9';
		a++;
		b++;
	}
	b='\0';
}

int Equal(char *a,char *b)
{
	while(*a==*b&&*a!='\0')
	{
		a++;
		b++;
	}
	if(*a=='\0'&&*a==*b)
		return 1;
	return 0;
}

int main()
{
	int total=0,i,flag=0;
	FILE *fin  = fopen ("namenum.in", "r");
    FILE *fout = fopen ("namenum.out", "w");
	FILE *fin1  = fopen ("dict.txt", "r");
	while((fscanf(fin1,"%s",&tar1[total][0]))!=EOF)
		total++;
	total--;
	for(i=0;i<=total;i++)
	{
		a2i(&tar1[i][0],&tar2[i][0]);
	}
	fscanf(fin,"%s",temp);
	for(i=0;i<=total;i++)
	{
		if(Equal(&tar2[i][0],temp))
		{
			flag=1;
			fprintf(fout,"%s\n",&tar1[i][0]);
		}
	}
	if(flag==0)
		fprintf(fout,"NONE\n");
	return 0;
}
