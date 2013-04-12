/*
ID: sunheco1
LANG: C
TASK: window
*/
#include<stdio.h>

struct Window{char name;int xmin,ymin,xmax,ymax;}window[64];
int total;

char tmp[32];

void deal(int total)
{
	char *p=tmp+4;
	window[total].xmin=0;
	while(*p!=',')
	{
		window[total].xmin*=10;
		window[total].xmin+=*p-'0';
		p++;
	}
	p++;
	window[total].ymin=0;
	while(*p!=',')
	{
		window[total].ymin*=10;
		window[total].ymin+=*p-'0';
		p++;
	}
	p++;
	window[total].xmax=0;
	while(*p!=',')
	{
		window[total].xmax*=10;
		window[total].xmax+=*p-'0';
		p++;
	}
	p++;
	window[total].ymax=0;
	while(*p!=')')
	{
		window[total].ymax*=10;
		window[total].ymax+=*p-'0';
		p++;
	}
	if(window[total].xmax<window[total].xmin)
	{
		window[total].xmax=window[total].xmax^window[total].xmin;
		window[total].xmin=window[total].xmax^window[total].xmin;
		window[total].xmax=window[total].xmax^window[total].xmin;
	}
	if(window[total].ymax<window[total].ymin)
	{
		window[total].ymax=window[total].ymax^window[total].ymin;
		window[total].ymin=window[total].ymax^window[total].ymin;
		window[total].ymax=window[total].ymax^window[total].ymin;
	}
}

int pos(char c)
{
	int i;
	for(i=1;i<=total;i++)
	{
		if(window[i].name==c)
			return i;
	}
	return 0;
}

int findout(int pos,int x1,int y1,int x2,int y2)
{
	int xmin,xmax,ymin,ymax,cnt;

	if(pos>total)
		return (x2-x1)*(y2-y1);

	cnt=0;

	if(window[pos].xmin>x2||window[pos].xmax<x1||window[pos].ymin>y2||window[pos].ymax<y1)
	{
		return findout(pos+1,x1,y1,x2,y2);
	}
	xmin=window[pos].xmin<x1?x1:window[pos].xmin;
	ymin=window[pos].ymin<y1?y1:window[pos].ymin;
	xmax=window[pos].xmax>x2?x2:window[pos].xmax;
	ymax=window[pos].ymax>y2?y2:window[pos].ymax;

	if(xmin>x1&&ymin>y1)
	{
		cnt+=findout(pos+1,x1,y1,xmin,ymin);
	}
	if(ymin>y1)
	{
		cnt+=findout(pos+1,xmin,y1,xmax,ymin);
	}
	if(xmax<x2&&ymin>y1)
	{
		cnt+=findout(pos+1,xmax,y1,x2,ymin);
	}
	if(xmin>x1)
	{
		cnt+=findout(pos+1,x1,ymin,xmin,ymax);
	}
	if(xmax<x2)
	{
		cnt+=findout(pos+1,xmax,ymin,x2,ymax);
	}
	if(xmin>x1&&ymax<y2)
	{
		cnt+=findout(pos+1,x1,ymax,xmin,y2);
	}
	if(ymax<y2)
	{
		cnt+=findout(pos+1,xmin,ymax,xmax,y2);
	}
	if(xmax<x2&&ymax<y2)
	{
		cnt+=findout(pos+1,xmax,ymax,x2,y2);
	}
	return cnt;
}

int main()
{
	int i,now;
	FILE *fin  = fopen ("window.in", "r");
    FILE *fout = fopen ("window.out", "w");
	while(fscanf(fin,"%s",tmp)!=EOF)
	{
		switch(tmp[0])
		{
		case 'w':
			total++;
			window[total].name=tmp[2];
			deal(total);
			break;
		case 't':
			now=pos(tmp[2]);
			window[0]=window[now];
			for(i=now;i<total;i++)
			{
				window[i]=window[i+1];
			}
			window[total]=window[0];
			break;
		case 'b':
			now=pos(tmp[2]);
			window[0]=window[now];
			for(i=now;i>0;i--)
			{
				window[i]=window[i-1];
			}
			break;
		case 'd':
			now=pos(tmp[2]);
			for(i=now;i<total;i++)
			{
				window[i]=window[i+1];
			}
			total--;
			break;
		case 's':
			now=pos(tmp[2]);
			//findout(now+1,window[now].xmin,window[now].ymin,window[now].xmax,window[now].ymax);
			fprintf(fout,"%0.3lf\n",(double)100*findout(now+1,window[now].xmin,window[now].ymin,window[now].xmax,window[now].ymax)/((window[now].xmax-window[now].xmin)*(window[now].ymax-window[now].ymin)));
			break;
		default:
			break;
		}
	}
	return 0;
}