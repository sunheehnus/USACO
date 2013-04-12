/*
ID: sunheco1
LANG: C
TASK: prime3
*/
#include<stdio.h>
#include<string.h>
char YES[100000];

int pos[100000];
int poe[100000];

int PRIME[2048][6];
int PRI[8888],visit[1024];

int output[1024][32];

int cnt,total;

int map[6][6];

FILE *fin,*fout;

void Deal5()
{
	int i,j,k,tar1,div,st1,ed1,st2,ed2,ti,tj,tk;
	tar1=map[5][1]*1000+map[5][2]*100+map[5][3]*10+map[5][4];
	st1=pos[tar1];
	ed1=poe[tar1];
	for(i=st1;i<=ed1;i++)
	{
		map[5][5]=PRIME[i][5];
		if(!(pos[map[1][2]*10000+map[2][2]*1000+map[3][2]*100+map[4][2]*10+map[5][2]]==0||pos[map[1][3]*10000+map[2][3]*1000+map[3][3]*100+map[4][3]*10+map[5][3]]==0||pos[map[1][4]*10000+map[2][4]*1000+map[3][4]*100+map[4][4]*10+map[5][4]]==0||pos[map[1][5]*10000+map[2][5]*1000+map[3][5]*100+map[4][5]*10+map[5][5]]==0||pos[map[2][1]*10000+map[2][2]*1000+map[2][3]*100+map[2][4]*10+map[2][5]]==0||pos[map[3][1]*10000+map[3][2]*1000+map[3][3]*100+map[3][4]*10+map[3][5]]==0||pos[map[4][1]*10000+map[4][2]*1000+map[4][3]*100+map[4][4]*10+map[4][5]]==0||pos[map[5][1]*10000+map[5][2]*1000+map[5][3]*100+map[5][4]*10+map[5][5]]==0||pos[map[1][1]*10000+map[2][2]*1000+map[3][3]*100+map[4][4]*10+map[5][5]]==0||pos[map[5][1]*10000+map[4][2]*1000+map[3][3]*100+map[2][4]*10+map[1][5]]==0))
		{
			total++;
			for(ti=1,tk=1;ti<=5;ti++)
			{
				for(tj=1;tj<=5;tj++,tk++)
					output[total][tk]=map[ti][tj];
			}
		}
	}
}
void Deal4()
{
	int i,j,k,tar1,tar2,div,st1,ed1,st2,ed2,ti,tj,tk;
	tar1=map[4][1]*100+map[4][2]*10+map[4][3];
	tar2=map[1][4]*100+map[2][4]*10+map[3][4];
	st1=pos[tar1];
	ed1=poe[tar1];
	st2=pos[tar2];
	ed2=poe[tar2];
	for(i=st2;i<=ed2;i++)
	{
		map[4][4]=PRIME[i][4];
		map[5][4]=PRIME[i][5];
		if(pos[map[1][2]*1000+map[2][2]*100+map[3][2]*10+map[4][2]]==0||pos[map[1][3]*1000+map[2][3]*100+map[3][3]*10+map[4][3]]==0||pos[map[1][4]*1000+map[2][4]*100+map[3][4]*10+map[4][4]]==0||pos[map[2][1]*1000+map[2][2]*100+map[2][3]*10+map[2][4]]==0||pos[map[3][1]*1000+map[3][2]*100+map[3][3]*10+map[3][4]]==0||pos[map[4][1]*1000+map[4][2]*100+map[4][3]*10+map[4][4]]==0||pos[map[5][1]*1000+map[5][2]*100+map[5][3]*10+map[5][4]]==0||pos[map[1][1]*1000+map[2][2]*100+map[3][3]*10+map[4][4]]==0||pos[map[5][1]*1000+map[4][2]*100+map[3][3]*10+map[2][4]]==0)
			continue;
		for(j=st1;j<=ed1;j++)
		{
			if(PRIME[j][4]<map[4][4])
				continue;
			else if(PRIME[j][4]>map[4][4])
				break;
			map[4][5]=PRIME[j][5];
			if(!(pos[map[1][5]*1000+map[2][5]*100+map[3][5]*10+map[4][5]]==0))
			{
				Deal5();
			}
		}
		
	}
}


void Deal3()
{
	int i,j,k,tar1,tar2,div,st1,ed1,st2,ed2,ti,tj,tk;
	tar1=map[3][1]*10+map[3][2];
	tar2=map[1][3]*10+map[2][3];
	st1=pos[tar1];
	ed1=poe[tar1];
	st2=pos[tar2];
	ed2=poe[tar2];
	for(i=st2;i<=ed2;i++)
	{
		map[3][3]=PRIME[i][3];
		map[4][3]=PRIME[i][4];
		map[5][3]=PRIME[i][5];
		if(pos[map[5][1]*10000+map[4][2]*1000+map[3][3]*100+map[2][4]*10+map[1][5]]==0||pos[map[1][2]*100+map[2][2]*10+map[3][2]]==0||pos[map[1][3]*100+map[2][3]*10+map[3][3]]==0||pos[map[2][1]*100+map[2][2]*10+map[2][3]]==0||pos[map[3][1]*100+map[3][2]*10+map[3][3]]==0||pos[map[4][1]*100+map[4][2]*10+map[4][3]]==0||pos[map[5][1]*100+map[5][2]*10+map[5][3]]==0||pos[map[1][1]*100+map[2][2]*10+map[3][3]]==0||pos[map[5][1]*100+map[4][2]*10+map[3][3]]==0)
			continue;
		for(j=st1;j<=ed1;j++)
		{
			if(PRIME[j][3]<map[3][3])
				continue;
			else if(PRIME[j][3]>map[3][3])
				break;
			map[3][4]=PRIME[j][4];
			map[3][5]=PRIME[j][5];
			if(!(pos[map[1][4]*100+map[2][4]*10+map[3][4]]==0||pos[map[1][5]*100+map[2][5]*10+map[3][5]]==0))
			{
				Deal4();
			}
		}
		
	}
}
void Deal2()
{
	int i,j,k,tar1,tar2,div,st1,ed1,st2,ed2,ti,tj,tk;
	tar1=map[2][1];
	tar2=map[1][2];
	st1=pos[tar1];
	ed1=poe[tar1];
	st2=pos[tar2];
	ed2=poe[tar2];
	for(i=st2;i<=ed2;i++)
	{
		map[2][2]=PRIME[i][2];
		map[3][2]=PRIME[i][3];
		map[4][2]=PRIME[i][4];
		map[5][2]=PRIME[i][5];
		if(pos[map[1][2]*10+map[2][2]]==0||pos[map[2][1]*10+map[2][2]]==0||pos[map[3][1]*10+map[3][2]]==0||pos[map[4][1]*10+map[4][2]]==0||pos[map[5][1]*10+map[5][2]]==0||pos[map[1][1]*10+map[2][2]]==0||pos[map[5][1]*10+map[4][2]]==0)
			continue;	
		for(j=st1;j<=ed1;j++)
		{
			if(PRIME[j][2]<map[2][2])
				continue;
			else if(PRIME[j][2]>map[2][2])
				break;
			map[2][3]=PRIME[j][3];
			map[2][4]=PRIME[j][4];
			map[2][5]=PRIME[j][5];
			if(!(pos[map[1][3]*10+map[2][3]]==0||pos[map[1][4]*10+map[2][4]]==0||pos[map[1][5]*10+map[2][5]]==0))
			{
				Deal3();
			}
		}
		
	}
}
void Deal1()
{
	int s,e,mid,st,ed,tar;
	tar=map[1][1];
	for(s=pos[tar];s<=poe[tar];s++)
	{
		map[2][1]=PRIME[s][2];
		if(map[2][1]==0)
			continue;
		map[3][1]=PRIME[s][3];
		if(map[3][1]==0)
			continue;
		map[4][1]=PRIME[s][4];
		if(map[4][1]==0)
			continue;
		map[5][1]=PRIME[s][5];
		if(map[5][1]==0)
			continue;
		for(e=pos[tar];e<=poe[tar];e++)
		{
			map[1][2]=PRIME[e][2];
			if(map[1][2]==0)
				continue;
			map[1][3]=PRIME[e][3];
			if(map[1][3]==0)
				continue;
			map[1][4]=PRIME[e][4];
			if(map[1][4]==0)
				continue;
			map[1][5]=PRIME[e][5];
			if(map[1][5]==0)
				continue;

			Deal2();
		}
	}
	return;
}
int cmp(int big,int small)
{
	int i;
	for(i=1;i<=25;i++)
	{
		if(output[big][i]>output[small][i])
			return 1;
		else if(output[big][i]<output[small][i])
			return 0;
	}
}
void quicksort(int s,int e)
{
	int i,j,mid,temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(s+e)>>1;
		temp=visit[mid];
		visit[mid]=visit[i];
		while(i<j)
		{
			while(i<j&&cmp(visit[j],temp))
				j--;
			visit[i]=visit[j];
			while(i<j&&cmp(temp,visit[i]))
				i++;
			visit[j]=visit[i];
		}
		visit[i]=temp;
		quicksort(s,i-1);
		quicksort(i+1,e);
	}
}
int main()
{
	int i,j,sum,start;
	fin=fopen ("prime3.in", "r");
    fout=fopen ("prime3.out", "w");
	fscanf(fin,"%d %d",&sum,&start);
	for(i=2;i<100000;i++)
	{
		if(YES[i]==0)
		{
			for(j=2;i*j<100000;j++)
				YES[i*j]=1;
		}
	}
	for(i=10000;i<100000;i++)
	{
		if(YES[i]==0&&(i/10000+(i/1000)%10+(i/100)%10+(i/10)%10+i%10==sum))
		{
			cnt++;
			PRIME[cnt][1]=i/10000;
			if(pos[i/10000]==0)
			{
				pos[i/10000]=cnt;
			}
			poe[i/10000]=cnt;
			PRIME[cnt][2]=(i/1000)%10;
			if(pos[i/1000]==0)
			{
				pos[i/1000]=cnt;
			}
			poe[i/1000]=cnt;
			PRIME[cnt][3]=(i/100)%10;
			if(pos[i/100]==0)
			{
				pos[i/100]=cnt;
			}
			poe[i/100]=cnt;
			PRIME[cnt][4]=(i/10)%10;
			if(pos[i/10]==0)
			{
				pos[i/10]=cnt;
			}
			poe[i/10]=cnt;
			PRIME[cnt][5]=i%10;
			if(pos[i]==0)
			{
				pos[i]=cnt;
			}
			poe[i]=cnt;
			PRI[cnt]=i;
		}
	}
	map[1][1]=start;
	Deal1();
	if(total==0)
		fprintf(fout,"NONE\n");
	else
	{
		for(i=1;i<=total;i++)
		{
			visit[i]=i;
		}
		quicksort(1,total);
		for(i=1;i<=total;i++)
		{
			if(i>1)
				fprintf(fout,"\n");
			for(j=1;j<=25;j++)
			{
				fprintf(fout,"%d",output[visit[i]][j]);
				if(j%5==0)
					fprintf(fout,"\n");
			}
		}
	}
	return 0;
}