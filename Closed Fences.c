/*
ID: sunheco1
LANG: C
TASK: fence4
*/
#include<stdio.h>
#include<math.h>
int tot,total,tx,ty,ans;

int p[9999][2];
struct Ver{int sx,sy,ex,ey;}v[9999];
struct VV{int sx,sy,ex,ey;double edgs,edge;}tar[9999],temp,cur;
int is[9999];

int Yes()
{
	int x1,y1,x2,y2,x3,y3,x4,y4;
	x1=temp.ex-temp.sx;
	y1=temp.ey-temp.sy;
	x2=cur.sx-temp.sx;
	y2=cur.sy-temp.sy;
	x3=cur.ex-temp.sx;
	y3=cur.ey-temp.sy;
	x4=tx-temp.sx;
	y4=ty-temp.sy;
	if(((x1*y2-y1*x2>0&&x1*y4-y1*x4<0)||((x1*y2-y1*x2<0&&x1*y4-y1*x4>0)))||((x1*y3-y1*x3>0&&x1*y4-y1*x4<0)||((x1*y3-y1*x3<0&&x1*y4-y1*x4>0))))
		return 1;
	return 0;
}

void Insert()
{
	int j;
	for(j=tot;j>0;j--)
	{
		cur=tar[j];
		if(cur.edgs==temp.edgs)
		{
			if(Yes())
			{
				if(cur.edge==temp.edge)
				{
					tar[j]=temp;
					return;
				}
				else if(cur.edge<temp.edge)
				{
					temp.edgs=tar[j].edge;
					tar[j].sx=temp.sx;
					tar[j].sy=temp.sy;
					tar[j].ex=temp.ex;
					tar[j].ey=temp.ey;
					Insert();
					return;
				}
				else
				{
					tar[j].edgs=temp.edge;
					tot++;
					tar[tot]=temp;
					return;
				}
			}
			else
			{
				if(cur.edge==temp.edge)
				{
					return;
				}
				else if(cur.edge<temp.edge)
				{
					temp.edgs=tar[j].edge;
					Insert();
					return;
				}
				else
				{
					tar[j].edgs=temp.edge;
					tot++;
					tar[tot]=cur;
					tar[tot].edge=temp.edge;
					return;
				}
			}
		}
		else if(cur.edge==temp.edge)
		{
			if(Yes())
			{
				if(cur.edgs<temp.edgs)
				{
					tar[j].edge=temp.edgs;
					tot++;
					tar[tot]=temp;
					return;
					
				}
				else
				{
					temp.edge=tar[j].edgs;
					tar[j].sx=temp.sx;
					tar[j].sy=temp.sy;
					tar[j].ex=temp.ex;
					tar[j].ey=temp.ey;
					Insert();
					return;
				}
			}
			else
			{
				if(cur.edgs<temp.edgs)
				{
					tar[j].edge=temp.edgs;
					tot++;
					tar[tot]=tar[j];
					tar[tot].edgs=temp.edgs;
					tar[tot].edge=temp.edge;
					return;
					
				}
				else
				{
					temp.edge=tar[j].edgs;
					Insert();
					return;
				}
			}
		}
	}
	tot++;
	tar[tot]=temp;
}

int Judge(int find,int now)
{
	int i,nx1,nx2,ny1,ny2,tx1,tx2,ty1,ty2,x1,x2,x3,y1,y2,y3,flag;
	nx1=v[now].sx;
	nx2=v[now].ex;
	ny1=v[now].sy;
	ny2=v[now].ey;
	for(i=find;i<now-1;i++)
	{
		flag=0;
		tx1=v[i].sx;
		tx2=v[i].ex;
		ty1=v[i].sy;
		ty2=v[i].ey;
		x1=nx2-nx1;
		y1=ny2-ny1;
		x2=tx1-nx1;
		y2=ty1-ny1;
		x3=tx2-nx1;
		y3=ty2-ny1;
		if((x1*y2-y1*x2>0&&x1*y3-y1*x3>0)||((x1*y2-y1*x2<0&&x1*y3-y1*x3<0)))
			continue;
		else if((x1*y2-y1*x2==0||x1*y3-y1*x3==0))
			flag=1;
		x1=tx2-tx1;
		y1=ty2-ty1;
		x2=nx1-tx1;
		y2=ny1-ty1;
		x3=nx2-tx1;
		y3=ny2-ty1;
		if((x1*y2-y1*x2>0&&x1*y3-y1*x3>0)||((x1*y2-y1*x2<0&&x1*y3-y1*x3<0)))
			continue;
		else if((x1*y2-y1*x2==0||x1*y3-y1*x3==0))
		{
			if(flag==1)
				continue;
			else
				return 1;
		}
		else 
			return 1;
	}
	return 0;
}

void Compute(int i)
{
	int x1,x2,y1,y2;
	double edg1,edg2;
	x1=v[i].sx-tx;
	y1=v[i].sy-ty;
	x2=v[i].ex-tx;
	y2=v[i].ey-ty;
	if(y1==0&&y2==0)
		return;
	if(y1==0)
	{
		if(x1>0)
		{
			if(y2>0)
			{
				temp.sx=v[i].sx;
				temp.sy=v[i].sy;
				temp.ex=v[i].ex;
				temp.ey=v[i].ey;
				temp.edgs=0;
				temp.edge=atan2(y2,x2);
			}
			else
			{
				temp.sx=v[i].ex;
				temp.sy=v[i].ey;
				temp.ex=v[i].sx;
				temp.ey=v[i].sy;
				temp.edgs=atan2(y2,x2);
				temp.edge=0;
			}
		}
		else
		{
			if(y2>0)
			{
				temp.sx=v[i].ex;
				temp.sy=v[i].ey;
				temp.ex=v[i].sx;
				temp.ey=v[i].sy;
				temp.edgs=atan2(y2,x2);
				temp.edge=3.141592654;
			}
			else
			{
				temp.sx=v[i].sx;
				temp.sy=v[i].sy;
				temp.ex=v[i].ex;
				temp.ey=v[i].ey;
				temp.edgs=-3.141592654;
				temp.edge=atan2(y2,x2);
			}
		}
		Insert();
	}
	else if(y2==0)
	{
		if(x2>0)
		{
			if(y1>0)
			{
				temp.sx=v[i].ex;
				temp.sy=v[i].ey;
				temp.ex=v[i].sx;
				temp.ey=v[i].sy;
				temp.edgs=0;
				temp.edge=atan2(y1,x1);
			}
			else
			{
				temp.sx=v[i].sx;
				temp.sy=v[i].sy;
				temp.ex=v[i].ex;
				temp.ey=v[i].ey;
				temp.edgs=atan2(y1,x1);
				temp.edge=0;
			}
		}
		else
		{
			if(y1>0)
			{
				temp.sx=v[i].sx;
				temp.sy=v[i].sy;
				temp.ex=v[i].ex;
				temp.ey=v[i].ey;
				temp.edgs=atan2(y1,x1);
				temp.edge=3.141592654;
			}
			else
			{
				temp.sx=v[i].ex;
				temp.sy=v[i].ey;
				temp.ex=v[i].sx;
				temp.ey=v[i].sy;
				temp.edgs=-3.141592654;
				temp.edge=atan2(y1,x1);
			}
		}
		Insert();
	}
	else
	{
		edg1=atan2(y1,x1);
		edg2=atan2(y2,x2);
		if(edg1==edg2)
			return;
		if(edg1-edg2>3.141592654)
		{
			temp.sx=v[i].sx;
			temp.sy=v[i].sy;
			temp.ex=v[i].ex;
			temp.ey=v[i].ey;
			temp.edgs=edg1;
			temp.edge=3.141592654;
			Insert();
			temp.edgs=-3.141592654;
			temp.edge=edg2;
			Insert();
		}
		else if(edg2-edg1>3.141592654)
		{
			temp.sx=v[i].sx;
			temp.sy=v[i].sy;
			temp.ex=v[i].ex;
			temp.ey=v[i].ey;
			temp.edgs=-3.141592654;
			temp.edge=edg1;
			Insert();
			temp.edgs=edg2;
			temp.edge=3.141592654;
			Insert();
		}
		else
		{
			if(edg1<edg2)
			{
				temp.sx=v[i].sx;
				temp.sy=v[i].sy;
				temp.ex=v[i].ex;
				temp.ey=v[i].ey;
				temp.edgs=edg1;
				temp.edge=edg2;
			}
			else
			{
				temp.sx=v[i].ex;
				temp.sy=v[i].ey;
				temp.ex=v[i].sx;
				temp.ey=v[i].sy;
				temp.edgs=edg2;
				temp.edge=edg1;
			}
			Insert();
		}
	}
}

int find(int j)
{
	int i;
	for(i=1;i<=tot;i++)
	{
		if(v[j].ex==tar[i].ex&&v[j].ey==tar[i].ey&&v[j].sx==tar[i].sx&&v[j].sy==tar[i].sy)
			return 1;
		else if(v[j].ex==tar[i].sx&&v[j].ey==tar[i].sy&&v[j].sx==tar[i].ex&&v[j].sy==tar[i].ey)
			return 1;
	}
	return 0;
}

int main()
{
	int i;
	FILE *fin  = fopen ("fence4.in", "r");
    FILE *fout = fopen ("fence4.out", "w");
	fscanf(fin,"%d",&total);
	fscanf(fin,"%d %d",&tx,&ty);
	for(i=1;i<=total;i++)
		fscanf(fin,"%d %d",&p[i][0],&p[i][1]);
	for(i=2;i<=total;i++)
	{
		v[i-1].sx=p[i-1][0];
		v[i-1].sy=p[i-1][1];
		v[i-1].ex=p[i][0];
		v[i-1].ey=p[i][1];
	}
	v[total].sx=p[total][0];
	v[total].sy=p[total][1];
	v[total].ex=p[1][0];
	v[total].ey=p[1][1];
	for(i=3;i<total;i++)
	{
		if(Judge(1,i))
		{
			fprintf(fout,"NOFENCE\n");
			return 0;
		}
	}
	if(Judge(2,total))
	{
		fprintf(fout,"NOFENCE\n");
		return 0;
	}
	for(i=1;i<=total;i++)
	{
		Compute(i);
	}
	for(i=1;i<=total;i++)
	{
		if(find(i))
		{
			ans++;
			is[i]=1;
		}
	}
	fprintf(fout,"%d\n",ans);
	for(i=1;i<total-1;i++)
	{
		if(is[i])
			fprintf(fout,"%d %d %d %d\n",v[i].sx,v[i].sy,v[i].ex,v[i].ey);
	}
	if(is[total])
		fprintf(fout,"%d %d %d %d\n",v[total].ex,v[total].ey,v[total].sx,v[total].sy);
	if(is[total-1])
		fprintf(fout,"%d %d %d %d\n",v[total-1].sx,v[total-1].sy,v[total-1].ex,v[total-1].ey);
	return 0;
}
//4 1 1 1 1 4 1 2 0 3 0
//13 5 5 0 0 7 0 5 2 7 5 5 7 3 5 4 9 1 8 2 5 0 9 -2 7 0 3 -3 1