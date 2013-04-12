/*
ID: sunheco1
LANG: C
TASK: shopping
*/
#include<stdio.h>
#include<string.h>
struct Union{int code,tot;}tar[11],target[111][11],in[111][11];

int total[111],price[111],map[11][11][11][11][11];

int i,j,k,i1,i2,i3,i4,i5,t1,t2,t3,t4,t5,c,tot,p,dc,cnt,*temp;

void quicksort(int s,int e,struct Union *tar)
{
	int i,j,mid;
	struct Union temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=i+j>>1;
		temp=tar[mid];
		tar[mid]=tar[s];
		while(i<j)
		{
			while(i<j&&tar[j].code>=temp.code)
				j--;
			tar[i]=tar[j];
			while(i<j&&tar[i].code<=temp.code)
				i++;
			tar[j]=tar[i];
		}
		tar[i]=temp;
		quicksort(s,i-1,tar);
		quicksort(i+1,e,tar);
	}
}

int find(int l)
{
	int i,j,c,k;
	for(j=1,i=1;j<=total[l];j++)
	{
		c=in[l][j].code;
		k=in[l][j].tot;
		for(;i<=tot;i++)
		{
			if(tar[i].code==c)
				break;
		}
		if(i>tot||tar[j].tot<k)
			return 0;
	}
	return 1;
}

int main()
{
	FILE *fin  = fopen ("shopping.in", "r");
    FILE *fout = fopen ("shopping.out", "w");
	fscanf(fin,"%d",&dc);
	for(i=1;i<=dc;i++)
	{
		fscanf(fin,"%d",total+i);
		for(j=1;j<=total[i];j++)
		{
			fscanf(fin,"%d %d",&in[i][j].code,&in[i][j].tot);
		}
		fscanf(fin,"%d",price+i);
	}
	fscanf(fin,"%d",&tot);
	for(i=1;i<=tot;i++)
	{
		fscanf(fin,"%d %d %d",&c,&k,&p);
		tar[i].code=c;
		tar[i].tot=k;
		dc++;
		in[dc][1].code=c;
		in[dc][1].tot=1;
		price[dc]=p;
		total[dc]=1;
	}
	for(i=1;i<=dc;i++)
	{
		quicksort(1,total[i],&in[i][0]);
	}
	quicksort(1,tot,&tar[0]);
	for(i=1,j=0;i<=dc;i++)
	{
		if(!find(i))
			continue;
		j++;
		for(k=1;k<=total[i];k++)
		{
			in[j][k]=in[i][k];
		}
		price[j]=price[i];
		total[j]=total[i];
	}
	dc=j;
	for(i=1;i<=dc;i++)
	{
		for(j=1,k=1;j<=total[i];j++)
		{
			for(;tar[k].code!=in[i][j].code;k++);
			target[i][k]=in[i][j];
		}
	}
	for(i1=0;i1<=6;i1++)
	{
		for(i2=0;i2<=6;i2++)
		{
			for(i3=0;i3<=6;i3++)
			{
				for(i4=0;i4<=6;i4++)
				{
					for(i5=0;i5<=6;i5++)
					{
						map[i1][i2][i3][i4][i5]=-1;
					}
				}
			}
		}
	}
	map[0][0][0][0][0]=0;
	for(i=1;i<=dc;i++)
	{
		t1=target[i][1].tot;
		t2=target[i][2].tot;
		t3=target[i][3].tot;
		t4=target[i][4].tot;
		t5=target[i][5].tot;
		for(i1=0;i1+t1<=tar[1].tot;i1++)
		{
			for(i2=0;i2+t2<=tar[2].tot;i2++)
			{
				for(i3=0;i3+t3<=tar[3].tot;i3++)
				{
					for(i4=0;i4+t4<=tar[4].tot;i4++)
					{
						for(i5=0;i5+t5<=tar[5].tot;i5++)
						{
							if(map[i1][i2][i3][i4][i5]==-1)
								continue;
							if(map[i1+t1][i2+t2][i3+t3][i4+t4][i5+t5]==-1||map[i1+t1][i2+t2][i3+t3][i4+t4][i5+t5]>map[i1][i2][i3][i4][i5]+price[i])
								map[i1+t1][i2+t2][i3+t3][i4+t4][i5+t5]=map[i1][i2][i3][i4][i5]+price[i];
						}
					}
				}
			}
		}
	}
	fprintf(fout,"%d\n",map[tar[1].tot][tar[2].tot][tar[3].tot][tar[4].tot][tar[5].tot]);
	return 0;
}