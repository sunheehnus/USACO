/*
ID: sunheco1
LANG: C
TASK: ride 
*/
#include<stdio.h>
int main() 
{
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char target1[55],target2[55];
	int tar1,tar2,i;
    fscanf (fin, "%s",target1);
	fscanf (fin, "%s",target2);	
    for(i=0,tar1=1;target1[i]!='\0';i++) 
	{
		tar1=(tar1*(target1[i]-'A'+1))%47;
	}
	for(i=0,tar2=1;target2[i]!='\0';i++)
	{
		tar2=(tar2*(target2[i]-'A'+1))%47;
	}
	if(tar1==tar2)
		fprintf(fout,"GO\n");
	else 
		fprintf(fout,"STAY\n");
    return 0;
}
