/*
ID: sunheco1
LANG: C
TASK: fence8
*/
#include<stdio.h>

int ntotal,rtotal;

int boards[64],rails[1024],left[1024],PROVIDE,LEFT,flag,visit[1024],lv;

void quicksort(int *a,int s,int e)
{
	int i,j,mid,temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(s+e)>>1;
		temp=a[mid];
		a[mid]=a[i];
		while(i<j)
		{
			while(i<j&&temp<=a[j])
				j--;
			a[i]=a[j];
			while(i<j&&temp>=a[i])
				i++;
			a[j]=a[i];
		}
		a[i]=temp;
		quicksort(a,s,i-1);
		quicksort(a,i+1,e);
	}
}

int min()
{
	int i;
	i=1;
	while(visit[i])
		i++;
	return rails[i];
}
int continueJudger(int i,int now)
{
	while(rails[i]==rails[i+1]&&i+1<=now&&visit[i+1])
		i++;
	if(i+1<=now&&rails[i]==rails[i+1])
		return 1;
	return 0;
}
void find(int r,int b,int now)
{
	int i;
	for(i=now;PROVIDE>=LEFT&&i>0;i--)
	{
		if(flag)
			return;
		if(visit[i]||i!=now&&rails[i]==rails[i+1]&&continueJudger(i,now))
			continue;
		if(!visit[i]&&rails[i]<=boards[b])
		{
			if(LEFT-rails[i]==0)
			{
				flag=1;
				return;
			}
			visit[i]=1;
			boards[b]-=rails[i];
			PROVIDE-=rails[i];
			LEFT-=rails[i];
			if(boards[b]<min())
			{
				PROVIDE-=boards[b];
				if(PROVIDE>=LEFT)
					find(r,b+1,r);
				PROVIDE+=boards[b];
			}
			else
				find(r,b,i-1);
			visit[i]=0;
			boards[b]+=rails[i];
			PROVIDE+=rails[i];
			LEFT+=rails[i];
		}
	}
}

int main()
{
	int i,pro,start,end,mid;
	FILE *fin  = fopen ("fence8.in", "r");
    FILE *fout = fopen ("fence8.out", "w");
	fscanf(fin,"%d",&ntotal);
	for(i=1;i<=ntotal;i++)
		fscanf(fin,"%d",boards+i);
	fscanf(fin,"%d",&rtotal);
	for(i=1;i<=rtotal;i++)
		fscanf(fin,"%d",rails+i);
	quicksort(boards,1,ntotal);
	quicksort(rails,1,rtotal);
	for(i=1;i<=rtotal;i++)
	{
		left[i]=left[i-1]+rails[i];
	}
	for(i=1;i<=ntotal;i++)
		PROVIDE+=boards[i];
	for(i=1;i<rtotal;i++)
	{
		if(left[i]>=PROVIDE)
			break;
	}
	start=1;
	end=i;
	pro=PROVIDE;
	while(start<=end)
	{
		mid=(start+end)>>1;
		flag=0;
		lv=1;
		LEFT=left[mid];
		PROVIDE=pro;
		while(boards[lv]<rails[1])
		{
			PROVIDE-=boards[lv];
			lv++;
		}
		find(mid,lv,mid);
		if(flag)
			start=mid+1;
		else
			end=mid-1;
	}
	fprintf(fout,"%d\n",end);
	return 0;
}