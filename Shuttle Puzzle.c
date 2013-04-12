/*
ID: sunheco1
LANG: C
TASK: shuttle
*/
#include<stdio.h>
int route[262144],pre[262144],level[262144],out[262144];
int hash[1048576];

int HASH(int key)
{
	int i;
	for(i=key%1048573;hash[i]!=0&&hash[i]!=key;i++);
	return i;
}

int main()
{
	int i,j,tot,N,tmp,tar,spacepos,value,cnt,tv,H,L,judge,limit;
	FILE *fin  = fopen ("shuttle.in", "r");
    FILE *fout = fopen ("shuttle.out", "w");
	fscanf(fin,"%d",&N);
	limit=N*(N+2);
	tmp=(1<<N)-1;
	tar=(tmp<<(N+5))+N+1;
	tmp=(tmp<<5)+N+1;
	route[0]=tmp;
	hash[HASH(tmp)]=tmp;
	cnt=0;

	for(i=0;route[i]!=tar;i++)
	{
		if(level[i]==limit)
			continue;
		spacepos=route[i]&0x1f;
		value=route[i]>>5;
		if(spacepos>=3&&((value>>((N<<1)-spacepos+1))&1)==1&&((value>>((N<<1)-spacepos+2))&1)==0)
		{
			tmp=3<<((N<<1)-spacepos+1);
			tmp=((tmp^value)<<5)+spacepos-2;
			judge=HASH(tmp);
			if(hash[judge]==0)
			{
				cnt++;
				route[cnt]=tmp;
				pre[cnt]=i;
				level[cnt]=level[i]+1;
				hash[judge]=tmp;
			}
		}
		if(spacepos>1&&(((value)>>((N<<1)-spacepos+1))&1)==0)
		{
			tmp=route[i]-1;
			judge=HASH(tmp);
			if(hash[judge]==0)
			{
				cnt++;
				route[cnt]=tmp;
				pre[cnt]=i;
				level[cnt]=level[i]+1;
				hash[judge]=tmp;
			}
		}
		if(spacepos<=(N<<1)&&(((value)>>((N<<1)-spacepos))&1)==1)
		{
			tmp=route[i]+1;
			judge=HASH(tmp);
			if(hash[judge]==0)
			{
				cnt++;
				route[cnt]=tmp;
				pre[cnt]=i;
				level[cnt]=level[i]+1;
				hash[judge]=tmp;
			}
		}
		if(spacepos<(N<<1)&&(((value>>((N<<1)-spacepos-1))&1))==1&&(((value>>((N<<1)-spacepos))&1))==0)
		{
			tmp=3<<((N<<1)-spacepos-1);
			tmp=((tmp^value)<<5)+spacepos+2;
			judge=HASH(tmp);
			if(hash[judge]==0)
			{
				cnt++;
				route[cnt]=tmp;
				pre[cnt]=i;
				level[cnt]=level[i]+1;
				hash[judge]=tmp;
			}
		}
	}
	cnt=0;
	while(i)
	{
		cnt++;
		out[cnt]=route[i]&0x1f;
		i=pre[i];
	}
	for(tmp=0;cnt>0;cnt--,tmp++)
	{
		if(tmp!=0&&tmp%20==0)
			fprintf(fout,"\n");
		if(tmp%20)
			fprintf(fout," ");
		fprintf(fout,"%d",out[cnt]);	
	}
	fprintf(fout,"\n");
	return 0;
}

//3 8 15 24 35 48 63 80 99 120 143 168 