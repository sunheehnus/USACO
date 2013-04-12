/*
ID: sunheco1
LANG: C
TASK: lgame
*/
#include<stdio.h>

#include<string.h>

char value[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7,};

char is[26],je[26];

int sort3[40001],sort4[40001],sort5[40001],sort6[40001],sort7[40001];

int tot3,tot4,tot5,tot6,tot7,tot;

char sum3[40001],sum4[40001],sum5[40001],sum6[40001],sum7[40001],string3[40001][4],string4[40001][5],string5[40001][6],string6[40001][7],string7[40001][8];

char tar[8],lenth;

int max;

char map[40001][9];

int output[40001],rs;

int OK(char *a,char *b)
{
	while(1)
	{
		if(*a==' ')
		{
			a++;
			continue;
		}
		if(*b==' ')
		{
			b++;
			continue;
		}
		if(*a<*b)
			return 0;
		else if(*a>*b)
			return 1;
		a++;
		b++;
	}
}

void quicksort(int *sort,char *sum,int s,int e)
{
	int i,j,mid,temp;
	if(s<e)
	{
		i=s;
		j=e;
		mid=(s+e)>>1;
		temp=sort[mid];
		sort[mid]=sort[i];
		while(i<j)
		{
			while(i<j&&(sum[sort[j]]>=sum[temp]))
				j--;
			sort[i]=sort[j];
			while(i<j&&(sum[sort[i]]<=sum[temp]))
				i++;
			sort[j]=sort[i];
		}
		sort[i]=temp;
		quicksort(sort,sum,s,i-1);
		quicksort(sort,sum,i+1,e);
	}
}

int result()
{
	int i,find;
	for(i=1;output[i];i++);
	find=i;
	for(i++;i<=rs;i++)
	{
		if(! output[i]&&OK(&map[find][0],&map[i][0]))
			find=i;
	}
	output[find]=1;
	return find;
}

int main()
{
	FILE *fin1=fopen ("lgame.in", "r");
	FILE *fin2=fopen ("lgame.dict", "r");
	FILE *fout=fopen ("lgame.out", "w");
	char tmp[8];
	int i,j,key;
	fscanf(fin1,"%s",tar);
	for(i=0;tar[i]!='\0';i++)
	{
		is[tar[i]-'a']++;
	}
	lenth=i;
	fscanf(fin2,"%s",tmp);
	for(;tmp[0]!='.';fscanf(fin2,"%s",tmp))
	{
		memset(je,0,sizeof(je));
		for(i=0,key=0;tmp[i]!='\0';key+=value[tmp[i]-'a'],i++)
		{
			je[tmp[i]-'a']++;
			if(je[tmp[i]-'a']>is[tmp[i]-'a'])
				break;
		}
		if(tmp[i]!='\0')
			continue;
		tot++;
		switch(i)
		{
		case 3:
			tot3++;
			string3[tot3][0]=tmp[0];
			string3[tot3][1]=tmp[1];
			string3[tot3][2]=tmp[2];
			sum3[tot3]=key;
			break;
		case 4:
			tot4++;
			string4[tot4][0]=tmp[0];
			string4[tot4][1]=tmp[1];
			string4[tot4][2]=tmp[2];
			string4[tot4][3]=tmp[3];
			sum4[tot4]=key;
			break;
		case 5:
			tot5++;
			string5[tot5][0]=tmp[0];
			string5[tot5][1]=tmp[1];
			string5[tot5][2]=tmp[2];
			string5[tot5][3]=tmp[3];
			string5[tot5][4]=tmp[4];
			sum5[tot5]=key;
			break;
		case 6:
			tot6++;
			string6[tot6][0]=tmp[0];
			string6[tot6][1]=tmp[1];
			string6[tot6][2]=tmp[2];
			string6[tot6][3]=tmp[3];
			string6[tot6][4]=tmp[4];
			string6[tot6][5]=tmp[5];
			sum6[tot6]=key;
			break;
		case 7:
			tot7++;
			string7[tot7][0]=tmp[0];
			string7[tot7][1]=tmp[1];
			string7[tot7][2]=tmp[2];
			string7[tot7][3]=tmp[3];
			string7[tot7][4]=tmp[4];
			string7[tot7][5]=tmp[5];
			string7[tot7][6]=tmp[6];
			sum7[tot7]=key;
			break;
		}
	}
	for(i=1;i<=tot3;i++)
		sort3[i]=i;
	quicksort(sort3,sum3,1,tot3);
	for(i=1;i<=tot4;i++)
		sort4[i]=i;
	quicksort(sort4,sum4,1,tot4);
	for(i=1;i<=tot5;i++)
		sort5[i]=i;
	quicksort(sort5,sum5,1,tot5);
	for(i=1;i<=tot6;i++)
		sort6[i]=i;
	quicksort(sort6,sum3,1,tot6);
	for(i=1;i<=tot7;i++)
		sort7[i]=i;
	quicksort(sort7,sum7,1,tot7);
	if(sum3[sort3[tot3]]>max)
		max=sum3[sort3[tot3]];
	if(sum4[sort4[tot4]]>max)
		max=sum4[sort4[tot4]];
	if(sum5[sort5[tot5]]>max)
		max=sum5[sort5[tot5]];
	if(sum6[sort6[tot6]]>max)
		max=sum6[sort6[tot6]];
	if(sum7[sort7[tot7]]>max)
		max=sum7[sort7[tot7]];
	for(i=tot3;i>0;i--)
	{
		memset(je,0,sizeof(je));
		je[string3[sort3[i]][0]-'a']++;
		je[string3[sort3[i]][1]-'a']++;
		je[string3[sort3[i]][2]-'a']++;
		for(j=i-1;j>0;j--)
		{
			if(sum3[sort3[j]]+sum3[sort3[i]]<=max)
				break;
			je[string3[sort3[j]][0]-'a']++;
			je[string3[sort3[j]][1]-'a']++;
			je[string3[sort3[j]][2]-'a']++;
			if(je[string3[sort3[j]][0]-'a']>is[string3[sort3[j]][0]-'a']||je[string3[sort3[j]][1]-'a']>is[string3[sort3[j]][1]-'a']||je[string3[sort3[j]][2]-'a']>is[string3[sort3[j]][2]-'a'])
			{
				je[string3[sort3[j]][0]-'a']--;
				je[string3[sort3[j]][1]-'a']--;
				je[string3[sort3[j]][2]-'a']--;	
				continue;
			}
			je[string3[sort3[j]][0]-'a']--;
			je[string3[sort3[j]][1]-'a']--;
			je[string3[sort3[j]][2]-'a']--;	
			max=sum3[sort3[j]]+sum3[sort3[i]];
		}
	}
	for(i=tot4;i>0;i--)
	{
		memset(je,0,sizeof(je));
		je[string4[sort4[i]][0]-'a']++;
		je[string4[sort4[i]][1]-'a']++;
		je[string4[sort4[i]][2]-'a']++;
		je[string4[sort4[i]][3]-'a']++;
		for(j=tot3;j>0;j--)
		{
			if(sum3[sort3[j]]+sum4[sort4[i]]<=max)
				break;
			je[string3[sort3[j]][0]-'a']++;
			je[string3[sort3[j]][1]-'a']++;
			je[string3[sort3[j]][2]-'a']++;
			if(je[string3[sort3[j]][0]-'a']>is[string3[sort3[j]][0]-'a']||je[string3[sort3[j]][1]-'a']>is[string3[sort3[j]][1]-'a']||je[string3[sort3[j]][2]-'a']>is[string3[sort3[j]][2]-'a'])
			{
				je[string3[sort3[j]][0]-'a']--;
				je[string3[sort3[j]][1]-'a']--;
				je[string3[sort3[j]][2]-'a']--;	
				continue;
			}
			je[string3[sort3[j]][0]-'a']--;
			je[string3[sort3[j]][1]-'a']--;
			je[string3[sort3[j]][2]-'a']--;	
			max=sum3[sort3[j]]+sum4[sort4[i]];
		}
	}
	for(i=tot3;sum3[sort3[i]]==max;i--)
	{
		rs++;
		map[rs][0]=string3[sort3[i]][0];
		map[rs][1]=string3[sort3[i]][1];
		map[rs][2]=string3[sort3[i]][2];
	}
	for(i=tot4;sum4[sort4[i]]==max;i--)
	{
		rs++;
		map[rs][0]=string4[sort4[i]][0];
		map[rs][1]=string4[sort4[i]][1];
		map[rs][2]=string4[sort4[i]][2];
		map[rs][3]=string4[sort4[i]][3];
	}
	for(i=tot5;sum5[sort5[i]]==max;i--)
	{
		rs++;
		map[rs][0]=string5[sort5[i]][0];
		map[rs][1]=string5[sort5[i]][1];
		map[rs][2]=string5[sort5[i]][2];
		map[rs][3]=string5[sort5[i]][3];
		map[rs][4]=string5[sort5[i]][4];
	}
	for(i=tot6;sum6[sort6[i]]==max;i--)
	{
		rs++;
		map[rs][0]=string6[sort6[i]][0];
		map[rs][1]=string6[sort6[i]][1];
		map[rs][2]=string6[sort6[i]][2];
		map[rs][3]=string6[sort6[i]][3];
		map[rs][4]=string6[sort6[i]][4];
		map[rs][5]=string6[sort6[i]][5];
	}
	for(i=tot7;sum7[sort7[i]]==max;i--)
	{
		rs++;
		map[rs][0]=string7[sort7[i]][0];
		map[rs][1]=string7[sort7[i]][1];
		map[rs][2]=string7[sort7[i]][2];
		map[rs][3]=string7[sort7[i]][3];
		map[rs][4]=string7[sort7[i]][4];
		map[rs][5]=string7[sort7[i]][5];
		map[rs][6]=string7[sort7[i]][6];
	}
	for(i=tot3;i>0&&sum3[sort3[i]]<<1>=max;i--)
	{
		memset(je,0,sizeof(je));
		je[string3[sort3[i]][0]-'a']++;
		je[string3[sort3[i]][1]-'a']++;
		je[string3[sort3[i]][2]-'a']++;
		for(j=i-1;j>0&&sum3[sort3[j]]+sum3[sort3[i]]>=max;j--)
		{
			je[string3[sort3[j]][0]-'a']++;
			je[string3[sort3[j]][1]-'a']++;
			je[string3[sort3[j]][2]-'a']++;
			if(je[string3[sort3[j]][0]-'a']>is[string3[sort3[j]][0]-'a']||je[string3[sort3[j]][1]-'a']>is[string3[sort3[j]][1]-'a']||je[string3[sort3[j]][2]-'a']>is[string3[sort3[j]][2]-'a'])
			{
				je[string3[sort3[j]][0]-'a']--;
				je[string3[sort3[j]][1]-'a']--;
				je[string3[sort3[j]][2]-'a']--;	
				continue;
			}
			je[string3[sort3[j]][0]-'a']--;
			je[string3[sort3[j]][1]-'a']--;
			je[string3[sort3[j]][2]-'a']--;	
			rs++;
			if(OK(&string3[sort3[i]][0],&string3[sort3[j]][0]))
			{
				map[rs][0]=string3[sort3[j]][0];
				map[rs][1]=string3[sort3[j]][1];
				map[rs][2]=string3[sort3[j]][2];
				map[rs][3]=' ';
				map[rs][4]=string3[sort3[i]][0];
				map[rs][5]=string3[sort3[i]][1];
				map[rs][6]=string3[sort3[i]][2];
			}
			else
			{
				map[rs][4]=string3[sort3[j]][0];
				map[rs][5]=string3[sort3[j]][1];
				map[rs][6]=string3[sort3[j]][2];
				map[rs][3]=' ';
				map[rs][0]=string3[sort3[i]][0];
				map[rs][1]=string3[sort3[i]][1];
				map[rs][2]=string3[sort3[i]][2];
			}
		}
	}
	for(i=tot4;i>0;i--)
	{
		memset(je,0,sizeof(je));
		je[string4[sort4[i]][0]-'a']++;
		je[string4[sort4[i]][1]-'a']++;
		je[string4[sort4[i]][2]-'a']++;
		je[string4[sort4[i]][3]-'a']++;
		for(j=tot3;j>0&&sum3[sort3[j]]+sum4[sort4[i]]>=max;j--)
		{
			je[string3[sort3[j]][0]-'a']++;
			je[string3[sort3[j]][1]-'a']++;
			je[string3[sort3[j]][2]-'a']++;
			if(je[string3[sort3[j]][0]-'a']>is[string3[sort3[j]][0]-'a']||je[string3[sort3[j]][1]-'a']>is[string3[sort3[j]][1]-'a']||je[string3[sort3[j]][2]-'a']>is[string3[sort3[j]][2]-'a'])
			{
				je[string3[sort3[j]][0]-'a']--;
				je[string3[sort3[j]][1]-'a']--;
				je[string3[sort3[j]][2]-'a']--;	
				continue;
			}
			je[string3[sort3[j]][0]-'a']--;
			je[string3[sort3[j]][1]-'a']--;
			je[string3[sort3[j]][2]-'a']--;	
			rs++;
			if(OK(&string4[sort4[i]][0],&string3[sort3[j]][0]))
			{
				map[rs][0]=string3[sort3[j]][0];
				map[rs][1]=string3[sort3[j]][1];
				map[rs][2]=string3[sort3[j]][2];
				map[rs][3]=' ';
				map[rs][4]=string4[sort4[i]][0];
				map[rs][5]=string4[sort4[i]][1];
				map[rs][6]=string4[sort4[i]][2];
				map[rs][7]=string4[sort4[i]][3];
			}
			else
			{
				map[rs][5]=string3[sort3[j]][0];
				map[rs][6]=string3[sort3[j]][1];
				map[rs][7]=string3[sort3[j]][2];
				map[rs][4]=' ';
				map[rs][0]=string4[sort4[i]][0];
				map[rs][1]=string4[sort4[i]][1];
				map[rs][2]=string4[sort4[i]][2];
				map[rs][3]=string4[sort4[i]][3];
			}
		}
	}
	fprintf(fout,"%d\n",max);
	for(i=1;i<=rs;i++)
		fprintf(fout,"%s\n",&map[result()][0]);
	return 0;
}