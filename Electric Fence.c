/*
ID: sunheco1
LANG: C
TASK: fence9
*/
#include<stdio.h>

double tran(double a,double b)
{
	return a/b;
}

int main()
{
	int a,b,c,i,temp,temp1,temp2,result;
	double k,z,y1,k1,k2;
	FILE *fin  = fopen ("fence9.in", "r");
    FILE *fout = fopen ("fence9.out", "w");
	fscanf(fin,"%d %d %d",&a,&b,&c);
	result=0;
	if(c==a)
	{
		k=tran((double)b,(double)a);
		for(i=1;i<a;i++)
		{
			y1=k*(double)i;
			temp=(int)y1;
			if((double)temp>y1)
				temp--;
			if(y1-(double)temp<0.0001)
				temp--;
			result+=temp;
		}
	}
	else if(c>a)
	{
		k=tran((double)b,(double)a);
		for(i=1;i<=a;i++)
		{
			y1=k*(double)i;
			temp=(int)y1;
			if((double)temp>y1)
				temp--;
			if(y1-(double)temp<0.0001)
				temp--;
			result+=temp;
		}
		k=tran((double)b,(double)(a-c));
		z=tran((double)(b*c),(double)(-a+c));
		for(;i<c;i++)
		{
			y1=k*(double)i+z;
			temp=(int)y1;
			if((double)temp>y1)
				temp--;
			if(y1-(double)temp<0.0001)
				temp--;
			result+=temp;
		}
	}
	else
	{
		k1=tran((double)b,(double)a);
		for(i=1;i<c;i++)
		{
			y1=k1*(double)i;
			temp1=(int)y1;
			if((double)temp1>y1)
				temp1--;
			if(y1-(double)temp1<0.0001)
				temp1--;
			result+=temp1;
		}
		k2=tran((double)b,(double)(a-c));
		z=tran((double)(b*c),(double)(-a+c));
		for(;i<a;i++)
		{
			y1=k1*(double)i;
			temp1=(int)y1;
			if((double)temp1>y1)
				temp1--;
			if(y1-(double)temp1<0.0001)
				temp1--;

			y1=k2*(double)i+z;
			temp2=(int)y1;
			if((double)temp2<y1)
				temp2++;
			if((double)temp2-y1<0.0001)
				temp2++;
			result+=temp1-temp2+1;
		}
	}
	fprintf(fout,"%d\n",result);
	return 0;
}