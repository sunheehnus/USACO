/*
ID: sunheco1
LANG: C
TASK: packrec
*/
#include<stdio.h>
int a[5],b[5],cur,p[22222],max=99999999,flag,wa,wb;
void quick_sort(int s,int e)
{
	int i,j,mid,temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(i+j)/2;
		temp=p[mid];
		p[mid]=p[i];
		while(i<j)
		{
			while(i<j&&p[j]>=temp)
				j--;
			p[i]=p[j];
			while(i<j&&p[i]<=temp)
				i++;
			p[j]=p[i];
		}
		p[i]=temp;
		quick_sort(s,i-1);
		quick_sort(i+1,e);
	}
}
int mAx(int i,int j)
{
	return i>j?i:j;
}
void query1(int now,int w,int h)
{
	int th;
	if(now==4)
	{
		th=h>b[now]?h:b[now];
		if((w+a[now])*th<max)
		{
			max=(w+a[now])*th;
			cur=0;
			p[cur++]=(w+a[now])>th?th:(w+a[now]);
		}
		else if((w+a[now])*th==max)
		{
			p[cur++]=(w+a[now])>th?th:(w+a[now]);
		}
		th=h>a[now]?h:a[now];
		if((w+b[now])*th<max)
		{
			max=(w+b[now])*th;
			cur=0;
			p[cur++]=(w+b[now])>th?th:(w+b[now]);
		}
		else if((w+b[now])*th==max)
		{
			p[cur++]=(w+b[now])>th?th:(w+b[now]);
		}
	}
	else
	{
		query1(now+1,w+a[now],b[now]>h?b[now]:h);
		query1(now+1,w+b[now],a[now]>h?a[now]:h);
	}
}
int query2(int now,int w,int h)
{
	int tw;
	if(now==4)
	{
		tw=w>b[now]?w:b[now];
		if((h+a[now])*tw<max)
		{
			max=(h+a[now])*tw;
			cur=0;
			p[cur++]=(h+a[now])>tw?tw:(h+a[now]);
		}
		else if((h+a[now])*tw==max)
		{
			p[cur++]=(h+a[now])>tw?tw:(h+a[now]);
		}
		tw=w>a[now]?w:a[now];
		if((h+b[now])*tw<max)
		{
			max=(h+b[now])*tw;
			cur=0;
			p[cur++]=(h+b[now])>tw?tw:(h+b[now]);
		}
		else if((h+b[now])*tw==max)
		{
			p[cur++]=(h+b[now])>tw?tw:(h+b[now]);
		}
	}
	else
	{
		query2(now+1,w+a[now],b[now]>h?b[now]:h);
		query2(now+1,w+b[now],a[now]>h?a[now]:h);
	}
}
void query3(int now,int w,int h)
{
	int th;
	if(now==3)
	{
		query3(now+1,w>a[now]?w:a[now],h+b[now]);
		query3(now+1,w>b[now]?w:b[now],h+a[now]);
	}
	else if(now==4)
	{
		th=h>b[now]?h:b[now];
		if((w+a[now])*th<max)
		{
			max=(w+a[now])*th;
			cur=0;
			p[cur++]=(w+a[now])>th?th:(w+a[now]);
		}
		else if((w+a[now])*th==max)
		{
			p[cur++]=(w+a[now])>th?th:(w+a[now]);
		}
		th=h>a[now]?h:a[now];
		if((w+b[now])*th<max)
		{
			max=(w+b[now])*th;
			cur=0;
			p[cur++]=(w+b[now])>th?th:(w+b[now]);
		}
		else if((w+b[now])*th==max)
		{
			p[cur++]=(w+b[now])>th?th:(w+b[now]);
		}
	}
	else
	{
		query3(now+1,w+a[now],b[now]>h?b[now]:h);
		query3(now+1,w+b[now],a[now]>h?a[now]:h);
	}
}
void query4(int now,int w,int h)
{
	int th;
	if(now==2)
	{
		query4(now+1,w>a[now]?w:a[now],h+b[now]);
		query4(now+1,w>b[now]?w:b[now],h+a[now]);
	}
	else if(now==4)
	{
		th=h>b[now]?h:b[now];
		if((w+a[now])*th<max)
		{
			max=(w+a[now])*th;
			cur=0;
			p[cur++]=(w+a[now])>th?th:(w+a[now]);
		}
		else if((w+a[now])*th==max)
		{
			p[cur++]=(w+a[now])>th?th:(w+a[now]);
		}
		th=h>a[now]?h:a[now];
		if((w+b[now])*th<max)
		{
			max=(w+b[now])*th;
			cur=0;
			p[cur++]=(w+b[now])>th?th:(w+b[now]);
		}
		else if((w+b[now])*th==max)
		{
			p[cur++]=(w+b[now])>th?th:(w+b[now]);
		}
	}
	else
	{
		query4(now+1,w+a[now],b[now]>h?b[now]:h);
		query4(now+1,w+b[now],a[now]>h?a[now]:h);
	}
}
void query5(int now,int w1,int w,int h1,int h)
{
	int th,tw;
	if(now==1)
	{
		query5(now+1,a[now],a[now],b[now],b[now]);
		query5(now+1,b[now],b[now],a[now],a[now]);
	}
	if(now==2)
	{
		query5(now+1,b[now]<h?w1:a[now],a[now]+w,b[now]<h?b[now]:h,b[now]>h?b[now]:h);
		query5(now+1,a[now]<h?w1:b[now],b[now]+w,a[now]<h?a[now]:h,a[now]>h?a[now]:h);
	}
	if(now==3)
	{
		flag=a[now]-w1;
		wa=a[now];
		wb=b[now];
		query5(now+1,w1,w,h1,h+b[now]);
		flag=b[now]-w1;
		wa=b[now];
		wb=a[now];
		query5(now+1,w1,w,h1,h+a[now]);
	}
	if(now==4)
	{
		if(flag>=0)
		{
			tw=mAx(wa+a[now],w);
			th=mAx(h1+b[now],h);
			if(tw*th<max)
			{
				max=tw*th;
				cur=0;
				p[cur++]=tw>th?th:tw;
			}
			else if(tw*th==max)
			{
				p[cur++]=tw>th?th:tw;
			}
			tw=mAx(wa+b[now],w);
			th=mAx(h1+a[now],h);
			if(tw*th<max)
			{
				max=tw*th;
				cur=0;
				p[cur++]=tw>th?th:tw;
			}
			else if(tw*th==max)
			{
				p[cur++]=tw>th?th:tw;
			}
		}
		else
		{
			tw=mAx(wa+a[now],w);
			th=mAx(h-wb+b[now],h);
			if(tw*th<max)
			{
				max=tw*th;
				cur=0;
				p[cur++]=tw>th?th:tw;
			}
			else if(tw*th==max)
			{
				p[cur++]=tw>th?th:tw;
			}
			tw=mAx(wa+b[now],w);
			th=mAx(h-wb+a[now],h);
			if(tw*th<max)
			{
				max=tw*th;
				cur=0;
				p[cur++]=tw>th?th:tw;
			}
			else if(tw*th==max)
			{
				p[cur++]=tw>th?th:tw;
			}
			tw=mAx(w1+a[now],w);
			th=mAx(h1+b[now],h);
			if(tw*th<max)
			{
				max=tw*th;
				cur=0;
				p[cur++]=tw>th?th:tw;
			}
			else if(tw*th==max)
			{
				p[cur++]=tw>th?th:tw;
			}
			tw=mAx(w1+b[now],w);
			th=mAx(h1+a[now],h);
			if(tw*th<max)
			{
				max=tw*th;
				cur=0;
				p[cur++]=tw>th?th:tw;
			}
			else if(tw*th==max)
			{
				p[cur++]=tw>th?th:tw;
			}
		}
	}
}
void swap(i,j)
{
	a[i]=a[i]^a[j];
	a[j]=a[i]^a[j];
	a[i]=a[i]^a[j];
	b[i]=b[i]^b[j];
	b[j]=b[i]^b[j];
	b[i]=b[i]^b[j];
}
int main()
{
	int i;
	FILE *fin  = fopen ("packrec.in", "r");
    FILE *fout = fopen ("packrec.out", "w");
	for(i=1;i<=4;i++)
	{
		fscanf(fin,"%d %d",a+i,b+i);
	}
	query1(1,0,0);
	query2(1,0,0);
	swap(1,4);
	query2(1,0,0);
	swap(1,4);
	swap(2,4);
	query2(1,0,0);
	swap(2,4);
	swap(3,4);
	query2(1,0,0);
	swap(3,4);
	query3(1,0,0);
	swap(3,4);
	query3(1,0,0);
	swap(3,4);
	swap(1,3);
	query3(1,0,0);
	swap(3,4);
	query3(1,0,0);
	swap(3,4);
	swap(1,3);
	swap(2,3);
	query3(1,0,0);
	swap(3,4);
	query3(1,0,0);
	swap(3,4);
	swap(2,3);
	swap(1,4);
	query3(1,0,0);
	swap(3,4);
	query3(1,0,0);
	swap(3,4);
	swap(1,4);
	swap(2,4);
	query3(1,0,0);
	swap(3,4);
	query3(1,0,0);
	swap(3,4);
	swap(2,4);
	swap(1,3);
	swap(2,4);
	query3(1,0,0);
	swap(3,4);
	query3(1,0,0);
	swap(3,4);
	swap(2,4);
	swap(1,3);
	query4(1,0,0);
	swap(1,3);
	query4(1,0,0);
	swap(1,3);
	swap(1,4);
	query4(1,0,0);
	swap(1,4);
	swap(2,3);
	query4(1,0,0);
	swap(2,3);
	swap(2,4);
	query4(1,0,0);
	swap(2,4);
	swap(1,3);
	swap(2,4);
	query4(1,0,0);
	swap(2,4);
	swap(1,3);
	query5(1,0,0,0,0);
	swap(1,3);
	query5(1,0,0,0,0);
	swap(1,3);
	swap(1,4);
	query5(1,0,0,0,0);
	swap(1,4);
	swap(2,3);
	query5(1,0,0,0,0);
	swap(2,3);
	swap(2,4);
	query5(1,0,0,0,0);
	swap(1,3);	swap(1,3);
	swap(2,4);
	query5(1,0,0,0,0);
	swap(2,4);
	swap(1,3);
	quick_sort(0,cur-1);
	flag=p[0];
	wa=0;
	fprintf(fout,"%d\n%d %d\n",max,p[0],max/p[0]);
	while(wa<cur)
	{
		if(p[wa]==flag)
		{
			wa++;
			continue;
		}
		else
		{
			if(p[wa]>max/p[wa])
				break;
			fprintf(fout,"%d %d\n",p[wa],max/p[wa]);
			flag=p[wa];
		}
	}
	return 0;
}