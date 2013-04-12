/*
ID: sunheco1
LANG: C
TASK: barn1
*/
#include<stdio.h>
int map[222],mm[222],m,s,c,now;
int next(int i)
{
    while(map[i]==0)
       i++;
    return i;    
}
int find(int i)
{
    int j=i;
    while(map[i]==0)
       i++; 
    return i-j;  
}
int min()
{
    int i,j,min=2222;
    for(i=1;i<=now;i++)
    {
        if(mm[i]<min)
        {
           j=i;
           min=mm[j];
        }
    }  
    i=mm[j];
    mm[j]=2222;
    return i;
}
int main()
{
    int i,tar,tem=0;
    FILE *fin  = fopen ("barn1.in", "r");
    FILE *fout = fopen ("barn1.out", "w");
    fscanf(fin,"%d %d %d",&m,&s,&c);
    for(i=1;i<=c;i++)
    {
        fscanf(fin,"%d",&tar); 
        map[tar]=1;               
    }
    while(map[s]==0)
        s--;
    now=1;
    i=1;
    while(map[i]==0)
        i++;
    while(i<=s)
    {
        if(map[i])
        { 
            while(map[i])
               i++;
        }
        else
        {
            tar=find(i);
            i=next(i);
            mm[now]=tar; 
            now++; 
            continue;       
        } 
        tem++;     
    }
    now--;
    tar=c;
    while(tem>m)
    {
        tar+=min();
        tem--;          
    }
    fprintf(fout,"%d\n",tar);
    return 0;
}
