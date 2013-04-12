/*
ID: sunheco1
LANG: C
TASK: telecow
*/
#include <stdio.h>  
#include <string.h>  

int left[128],queue[128],visit[128],pre[128],getout[128];

int map[128][128],maptmp[128][128];

int source,sink,N,M,cnt;

int Exist()
{
	int tmp,h,r,i;
	memset(visit,0,sizeof(visit));
	tmp=h=r=0;
	queue[r++]=source;
	while(h!=r)
	{
		tmp=queue[h++];
		if(tmp==sink)
			break;
		for(i=1;i<=N;i++)
		{
			if(visit[i]==0&&left[i]!=0&&maptmp[tmp][i])
			{
				queue[r++]=i;
				pre[i]=tmp;
				visit[i]=1;
			}
		}
	}
	if(tmp==sink)
	{
		i=pre[sink];
		while(i!=source)
		{
			left[i]=0;
			i=pre[i];
		}
		return 1;
	}
	return 0;
}

int main()
{
	int i,j,s,t,tmp;
	FILE *fin  = fopen ("telecow.in", "r");
    FILE *fout = fopen ("telecow.out", "w");
	fscanf(fin,"%d %d %d %d",&N,&M,&source,&sink);
	for(i=1;i<=M;i++)
	{
		fscanf(fin,"%d %d",&s,&t);
		map[s][t]=map[t][s]=maptmp[s][t]=maptmp[t][s]=1;
	}
	memset(left,-1,sizeof(left));
	while(Exist())
	{
		cnt++;
	}
	fprintf(fout,"%d\n",cnt);

	for(i=1;i<=N&&cnt!=0;i++)
	{
		if(i==source||i==sink)
			continue;
		tmp=0;
		for(j=1;j<=N;j++)
			maptmp[i][j]=maptmp[j][i]=0;
		memset(left,-1,sizeof(left));
		while(Exist())
		{
			tmp++;
		}
		if(tmp!=cnt)
		{
			cnt--;
			if(cnt)
				fprintf(fout,"%d ",i);
			else
				fprintf(fout,"%d\n",i);
			getout[i]=1;
		}
		else
		{
			for(j=1;j<=N;j++)
			{
				if(getout[j]==1)
					continue;
				maptmp[i][j]=maptmp[j][i]=map[i][j];
			}
		}
	}
	return 0;
}
/*
3 2 1 2
1 3
2 3
*/
