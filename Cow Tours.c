/*
ID: sunheco1
LANG: C
TASK: cowtour
*/
#include<stdio.h>
#include<math.h>

struct Pos{int x;int y;};
struct Pos pos[555];

int map[555][555];
double space[555][555];



int U[555][555],u[555],visit[555];
double cur[555],max[555];
char target[555];

int tot,ut,u1,u2;

void DFS(int now,int tt)
{
	int i;
	visit[now]=1;
	U[tt][++u[tt]]=now;
	for(i=1;i<=tot;i++)
	{
		if(!visit[i]&&map[now][i])
		{
			DFS(i,tt);
		}
	}
}
int min(int j)
{
	int i,find;
	double m;
	m=10000000;
	find=0;
	for(i=1;i<=u[j];i++)
	{
		if(!visit[U[j][i]]&&cur[U[j][i]]<m)
		{
			m=cur[U[j][i]];
			find=U[j][i];
		}
	}
	return find;
}

void Find(int i)
{ 
	int j,k,now;
	double add;
	for(k=1;k<=u[i];k++)
	{
		for(j=1;j<=u[i];j++)
		{
			visit[U[i][j]]=0;
			cur[U[i][j]]=space[U[i][k]][U[i][j]];
		}
		visit[U[i][k]]=1;
		while((now=min(i))!=0)
		{
			visit[now]=1;
			add=cur[now];
			for(j=1;j<=u[i];j++)
			{
				if(!visit[U[i][j]]&&space[now][U[i][j]]+add<cur[U[i][j]])
					cur[U[i][j]]=space[now][U[i][j]]+add;
			}
		}
		add=0;
		for(j=1;j<=u[i];j++)
		{
			if(cur[U[i][j]]!=10000000&&cur[U[i][j]]>add)
				add=cur[U[i][j]];
		}
		max[U[i][k]]=add;
	}
}


int main()
{
	int i,j,k,l;
	double result,result1,result2,op,temp;
	FILE *fin  = fopen ("cowtour.in", "r");
    FILE *fout = fopen ("cowtour.out", "w");
	fscanf(fin,"%d",&tot);
	for(i=1;i<=tot;i++)
	{
		fscanf(fin,"%d %d",&(pos[i].x),&(pos[i].y));
	}
	for(i=1;i<=tot;i++)
	{
		fscanf(fin,"%s",target);
		for(j=0;j<tot;j++)
		{
			map[i][j+1]=target[j]-'0';
		}
	}
//	map[16][105]=map[105][16]=1;
	for(i=1;i<=tot;i++)
	{
		for(j=1;j<=tot;j++)
			space[i][j]=10000000;
	}
	for(i=1;i<=tot;i++)
	{
		for(j=1;j<=tot;j++)
		{
			if(map[i][j])
			{
				space[i][j]=sqrt((pos[i].x-pos[j].x)*(pos[i].x-pos[j].x)+(pos[i].y-pos[j].y)*(pos[i].y-pos[j].y));
			}
		}
	}
	for(i=1;i<=tot;i++)
	{
		if(!visit[i])
			DFS(i,++ut);
	}
	op=10000000;
	for(j=1;j<=ut;j++)
	{
		Find(j);
	}
	for(j=1,result1=0;j<=tot;j++)
	{
		if(max[j]>result1)
			result1=max[j];
	}
	for(i=1;i<=ut;i++)
	{
		for(j=i+1;j<=ut;j++)
		{
			for(k=1;k<=u[i];k++)
			{
				for(l=1;l<=u[j];l++)
				{
					result=sqrt((pos[U[i][k]].x-pos[U[j][l]].x)*(pos[U[i][k]].x-pos[U[j][l]].x)+(pos[U[i][k]].y-pos[U[j][l]].y)*(pos[U[i][k]].y-pos[U[j][l]].y));
					result+=max[U[i][k]]+max[U[j][l]];
					if(result<op)
						op=result;
				}
			}
		}
	}
	if(op<result1)
		op=result1;
	fprintf(fout,"%lf\n",op);
	return 0;
}


