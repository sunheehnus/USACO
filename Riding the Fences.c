/*
ID: sunheco1
LANG: C
TASK: fence
*/
#include<stdio.h>

struct Intersec{int p,visit;}is[555][1111];

int degree[555];

int total[555];

int cnt,i,j,s,e;

int tot1,tot2,map1[9999],map2[9999];

void quicksort(int s,int e,struct Intersec *tar)
{
	int i,j,mid;
	struct Intersec temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=i+j>>1;
		temp=tar[mid];
		tar[mid]=tar[s];
		while(i<j)
		{
			while(i<j&&tar[j].p>=temp.p)
				j--;
			tar[i]=tar[j];
			while(i<j&&tar[i].p<=temp.p)
				i++;
			tar[j]=tar[i];
		}
		tar[i]=temp;
		quicksort(s,i-1,tar);
		quicksort(i+1,e,tar);
	}
}
void make(int i)
{
	int j,k,flag;
	tot1++;
	map1[tot1]=i;	
	while(1)
	{
		for(j=1,flag=0;j<=total[i];j++)
		{
			if(!is[i][j].visit)
			{
				is[i][j].visit=1;
				flag=1;
				tot1++;
				map1[tot1]=is[i][j].p;
				degree[i]--;
				degree[is[i][j].p]--;
				break;
			}
		}
		if(!flag)
			break;
		for(k=1;k<=total[is[i][j].p];k++)
		{
			if(!is[is[i][j].p][k].visit&&is[is[i][j].p][k].p==i)
			{
				is[is[i][j].p][k].visit=1;
				break;
			}
		}
		i=is[i][j].p;
	}
}

void add(int i,int j,int cur)
{
	int tar,now,l,k;
 	tar=i;
	l=j;
	now=0;
	while(1)
	{
		for(j=l;j<=total[i];j++)
		{
			if(!is[i][j].visit)
			{
				is[i][j].visit=1;
				now++;
				map2[now]=is[i][j].p;
				degree[i]--;
				degree[is[i][j].p]--;
				break;
			}
		}
		for(k=1;k<=total[is[i][j].p];k++)
		{
			if(!is[is[i][j].p][k].visit&&is[is[i][j].p][k].p==i)
			{
				is[is[i][j].p][k].visit=1;
				break;
			}
		}
		i=is[i][j].p;
		l=1;
		if(i==tar)
			break;
	}
	for(i=tot1;i>cur;i--)
	{
		map1[i+now]=map1[i];
	}
	for(j=1,i++;j<=now;j++,i++)
		map1[i]=map2[j];
	tot1=tot2=tot1+now;
}

int main()
{
	FILE *fin = fopen ("fence.in", "r");  
	FILE *fout = fopen ("fence.out", "w");
	int find;
	fscanf(fin,"%d",&cnt);
	for(i=1;i<=cnt;i++)
	{
		fscanf(fin,"%d %d",&s,&e);
		total[s]++;
		is[s][total[s]].p=e;
		total[e]++;
		is[e][total[e]].p=s;
		degree[s]++;
		degree[e]++;
	}
	for(i=1;i<=cnt;i++)
	{
		quicksort(1,total[i],&is[i][0]);
	}
	for(i=1;i<=500;i++)
	{
		if(total[i])
		{
			s=i;
			break;
		}
	}
	for(;i<=500;i++)
	{
		if(total[i]&1)
		{
			s=i;
			break;
		}
	}
	make(s);
	tot2=tot1;
	for(i=1;i<=tot1;i++)
		map2[i]=map1[i]; 
	for(i=tot1-1;i>=1;i--)
	{
		if(!degree[map1[i]])
			continue;
 		for(j=1;j<=total[map1[i]];j++)
		{
			if(is[map1[i]][j].visit)
				continue;
			if(map1[i]>500)
				printf("%d",i);
			add(map1[i],j,i);
			i=tot1;
			break;
		}
	}
	for(i=1;i<=tot1;i++)
		fprintf(fout,"%d\n",map1[i]);
	return 0;
}


