/*
ID: sunheco1
LANG: C
TASK: prefix
*/
#include<stdio.h>

char pri[222][16],target[222222];
int plen[222],visit[222222]={1};

int totp,tlen;

void Initlen()
{
	int i,j;
	for(i=1;i<=totp;i++)
	{
		for(j=0;pri[i][j]!='\0';j++);
		plen[i]=j;
	}
	for(j=1;target[j]!='\0';j++);
		tlen=j-1;
}

int Is(char *a,char *b)
{
	while(*a!='\0'&&*a==*b)
	{
		a++;
		b++;
	}
	return *b=='\0'?1:0;
}

void Find(int i)
{
	char *tar=target+i+1;
	int j;
	for(j=1;j<=totp;j++)
	{
		if(Is(tar,&pri[j][0]))
			visit[i+plen[j]]=1;
	}
}

int main()
{
	int i;
	char *a=target+1;
	FILE *fin  = fopen ("prefix.in", "r");
    FILE *fout = fopen ("prefix.out", "w");
	for(totp=1;;totp++)
	{
		fscanf(fin,"%s",&pri[totp][0]);
		if(pri[totp][0]=='.')
			break;
	}
	totp--;
	while(fscanf(fin,"%s",a)!=EOF)
	{
		while(*a!='\0')
			a++;
	}
	Initlen();
	for(i=0;i<tlen;i++)
	{
		if(visit[i])
			Find(i);
	}
	for(i=tlen;visit[i]==0;i--);
	fprintf(fout,"%d\n",i);
	return 0;
}
