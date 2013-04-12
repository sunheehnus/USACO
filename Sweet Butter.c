/*
ID: sunheco1
LANG: C
TASK: butter
*/
#include<stdio.h>
#include<string.h>
int cows,tot,connect;

int pos[555],total[888],is[888],visit[888],map[888][888];

struct Con{int pos,lenth;}con[888][888];

struct Node{int pre,next,len;}node[888];

void Find(int now)
{
	int i,j,pos,cmp,cur,cnt,add,max,find;
	memset(visit,0,sizeof(visit));
	node[0].pre=-1;
	node[0].next=801;
	node[0].len=99999999;
	node[801].pre=0;
	node[801].next=-1;
	node[801].len=99999999;
	visit[now]=1;
	for(cnt=tot-1,find=now,add=0;cnt;cnt--)
	{
		j=find;
		cur=1;
		i=0;
		max=99999999;
		find=-1;
		while(1)
		{
			while(cur<=total[j]&&visit[con[j][cur].pos]==1)
				cur++;
			if(cur>total[j])
				break;
			cmp=con[j][cur].pos;
			while(node[i].next<cmp)
			{
				if(node[i].len<max)
				{
					max=node[i].len;
					find=i;
				}
				i=node[i].next;
			}
			if(node[i].next==cmp)
			{
				if(con[j][cur].lenth+add<node[node[i].next].len)
				{
					node[node[i].next].len=con[j][cur].lenth+add;		
				}
				cur++;
			}
			else
			{
				pos=con[j][cur].pos;
				node[pos].pre=i;
				node[pos].next=node[i].next;
				node[pos].len=con[j][cur].lenth+add;
				node[node[i].next].pre=pos;
				node[i].next=pos;
				cur++;
			}
		}
		while(node[i].next!=-1)
		{
			if(node[i].len<max)
			{
				max=node[i].len;
				find=i;
			}
			i=node[i].next;
		}
		add=node[find].len;
		node[node[find].next].pre=node[find].pre;
		node[node[find].pre].next=node[find].next;
		map[now][find]=map[find][now]=node[find].len;
		visit[find]=1;
	}
	
}

void quicksort(int s,int e,struct Con *tar)
{
	int i,j,mid;
	struct Con temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=i+j>>1;
		temp=tar[mid];
		tar[mid]=tar[i];
		while(i<j)
		{
			while(i<j&&tar[j].pos>=temp.pos)
				j--;
			tar[i]=tar[j];
			while(i<j&&tar[i].pos<=temp.pos)
				i++;
			tar[j]=tar[i];
		}
		tar[i]=temp;
		quicksort(s,i-1,tar);
		quicksort(i+1,e,tar);
	}
}

int main()
{
	int i,j,s,e,len,min,current;
	FILE *fin  = fopen ("butter.in", "r");
    FILE *fout = fopen ("butter.out", "w");
	fscanf(fin,"%d %d %d",&cows,&tot,&connect);
	for(i=1;i<=cows;i++)
	{
		fscanf(fin,"%d",pos+i);
	}
	for(i=1;i<=connect;i++)
	{
		fscanf(fin,"%d %d %d",&s,&e,&len);
		total[s]++;
		con[s][total[s]].pos=e;
		con[s][total[s]].lenth=len;
		total[e]++;
		con[e][total[e]].pos=s;
		con[e][total[e]].lenth=len;
	}
	for(i=1;i<=tot;i++)
	{
		map[i][i]=0;
		quicksort(1,total[i],&con[i][0]);
	}
	for(i=1;i<=cows;i++)
	{
		if(!is[pos[i]])
		{
			Find(pos[i]);
			is[pos[i]]=1;
		}
	}
	for(i=1,min=99999999;i<=tot;i++)
	{
		current=0;
		for(j=1;j<=cows;j++)
		{
			current+=map[i][pos[j]];
		}
		if(current<min)
			min=current;
	}
	fprintf(fout,"%d\n",min);
	return 0;
}