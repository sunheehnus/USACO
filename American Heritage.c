/*
ID: sunheco1
LANG: C
TASK: heritage
*/
#include<stdio.h>
#include<stdlib.h>
char mid[999],pre[999];
struct Tree{char value;struct Tree *lc,*rc;};

FILE *fin,*fout;

struct Tree * make(int s,int e)
{
	struct Tree * node;
	int m,i;
	if(s>e)
		return NULL;
	node=(struct Tree *)malloc(sizeof(struct Tree));
	node->value=pre[s];
	for(m=s;mid[m]!=pre[s];m++);
	for(i=s;i<m;i++)
		pre[i]=pre[i+1];
	node->lc=make(s,m-1);
	node->rc=make(m+1,e);
	return node;
}

void print(struct Tree * tree)
{
	if(tree->lc!=NULL)
		print(tree->lc);
	if(tree->rc!=NULL)
		print(tree->rc);
	fprintf(fout,"%c",tree->value);
}

int main()
{
	int i;
	struct Tree * tree;
	fin=fopen ("heritage.in", "r");
    fout=fopen ("heritage.out", "w");
	fscanf(fin,"%s",mid);
	fscanf(fin,"%s",pre);
	for(i=0;pre[i]!='\0';i++);
	tree=make(0,i-1);
	print(tree);
	fprintf(fout,"\n");
	return 0;
}