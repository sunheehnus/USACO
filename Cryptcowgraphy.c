/*
ID: sunheco1
LANG: C
TASK: cryptcow
*/
#include<stdio.h>


char temp[16][1024];
char target[128]={" Begin the Escape execution at the Break of Dawn\n"};

char visit[65535];
char hash[65536][128];

int cnt,flag,FUCK;

int CMP(char *a,int l)
{
	int i,k;
	if(l==0)
		return 1;
	for(i=0;target[i];i++)
	{
		k=1;
		while(target[i+k]==a[k])
		{
			if(k==l)
				return 1;
			k++;	
		}
		if(target[i+k]=='\0')
			return 0;
	}
	return 0;
}

int cutoff(int now)
{
	char *a=&temp[now][0];
	int i,j;
	i=1;
	for(;a[i];i=j)
	{
		j=i+1;
		while(a[j]&&a[j]!='C'&&a[j]!='O'&&a[j]!='W')
		{
			j++;
		}
		if(CMP(a+i,j-i-1)==0)
			return 1;
	}
	return 0;
}

int finde(char *a,int s)
{
	while(a[s]!='\0'&&a[s]!='W')
		s--;
	return s;
}
int find(char *a,char b,int s)
{
	while(a[s]!='\0'&&a[s]!=b)
		s++;
	return s;
}

int cmp(char *a,char *b)
{
	while(*a!='\0'&&*a==*b)
	{
		a++;
		b++;
	}
	if(*a=='\0')
		return 1;
	return 0;
}
int Hashbaby(char *a)
{
	int *b,i,key=0;
	b=(char *)(a-1); 
	for(i=0;b[i];i++)
	{
		key=key^(b[i]<<(i&15));
	}
	key=key&65535;
//	if(visit[key])
//		printf("%d\n",++FUCK);
	for(;visit[key];key++)
	{
		if(cmp(a,&hash[key][1]))
			return 0;
	}
	return key;
}

void Deal(int now,int st,int ed)
{
	int s,m,e,e1,i,j,k;
	char *a=&temp[now-1][0];
	if(flag==1)
		return;	
	if(now>cnt)
	{
		if(cmp(&temp[now-1][1],target+1))
		{
			flag=1;
		}
		return;
	}
	if(cutoff(now-1))
		return;

	

	while(a[st]!='C')
	{
		if(a[st]!=target[st]||a[st]=='O'||a[st]=='W')
			return;
		st++;
	}
	i=48;
	e1=ed;
	while(a[e1]!='W')
	{
		if(a[e1]!=target[i]||a[e1]=='C'||a[e1]=='O')
			return;
		i--;
		e1--;
	}
	j=Hashbaby(&temp[now-1][1]);
	if(j==0)
		return;
	for(i=1;a[i];i++)
		hash[j][i]=a[i];
	hash[j][i]=a[i];
	visit[j]=1;


	for(m=find(&temp[now-1][0],'O',1);temp[now-1][m];m=find(&temp[now-1][0],'O',m+1))
	{	
		for(s=st;temp[now-1][s];s=find(&temp[now-1][0],'C',s+1))
		{
			if(s>m)
				break;
			for(e=e1;temp[now-1][e];e=finde(&temp[now-1][0],e-1))
			{	
				if(e<m)
					break;
				for(i=1;i<s;i++)
				{
					temp[now][i]=temp[now-1][i];
				}
				for(j=i,k=m+1;k<e;k++,j++)
				{
					temp[now][j]=temp[now-1][k];
				}
				for(k=s+1;k<m;k++,j++)
				{
					temp[now][j]=temp[now-1][k];
				}
				for(k=e+1;temp[now-1][k]!='\0';k++,j++)
				{
					temp[now][j]=temp[now-1][k];
				}
				temp[now][j]=temp[now-1][k];
				Deal(now+1,st,ed-3);
			}
		}		
	}
}

int main()
{
	FILE *fin  = fopen ("cryptcow.in", "r");
    FILE *fout = fopen ("cryptcow.out", "w");
	int i,cc,oc,wc;
	fgets(&temp[0][1],128,fin);
	for(cnt=1;temp[0][cnt]!='\0';cnt++);
	cnt--;
	for(i=1,cc=0,oc=0,wc=0;i<=cnt;i++)
	{
		switch(temp[0][i])
		{
		case 'C':
			cc++;
			break;
		case 'O':
			oc++;
			break;
		case 'W':
			wc++;
			break;
		default:;
		}
	}
	if(cc!=oc||cc!=wc||oc!=wc||(cnt-48)%3!=0)
	{
		fprintf(fout,"0 0\n");
		return 0;
	}
	cnt=(cnt-48)/3;
	Deal(1,1,cnt*3+48);
	if(flag==0)
	{
		fprintf(fout,"0 0\n");
	}
	else
		fprintf(fout,"1 %d\n",cnt);
	return 0;
}