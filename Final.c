#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<stdlib.h>
//#include<Windows.h>
#include<unistd.h>
//#include<dos.h>
void await()
{
	int i;
	printf("\n\nProcess Executing");
	for(i=0; i<5; i++)
	{
		printf(".");
		sleep(1);
	}
}
int main()
{
    int et[20],at[10],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10];
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];
    //clrscr();
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter process name,arrivaltime,execution time & priority:");
        //flushall();
        scanf("%s%d%d%d",pn[i],&at[i],&et[i],&p[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
//    printf("\nPname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime");
//    for(i=0; i<n; i++)
//        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],wt[i],ta[i]);
    printf("\n");
	int newP[10];
	
	
	int pj = 0, x, y;
	for(j=pj; j<1; j++)
	{
		
		printf("\nPname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime");
		for(i=j; i<n; i++){
			
			printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],wt[i],ta[i]);
		}
		await();
        printf("\n\nOne process has completed the execution.\n");
        pj++;
	}
	for(i=0; i<n; i++)
	p[i] = (1+wt[i])/et[i];
	for(j=pj; j<n; j++)
	{
		
		printf("\nPname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime");
		for(i=j; i<n; i++){
			int chn = abs(wt[i] - ta[i-1]);
		int cht = abs(ta[i] - ta[i-1]);
			printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],chn,cht);
		}
		await();
        printf("\n\nOne process has completed the execution.\n");
        for(x=0; x<n; x++)
        for(y=0; y<n; y++)
        {
            if(p[x]<p[y])
            {
                temp=p[x];
                p[x]=p[y];
                p[y]=temp;
                temp=at[x];
                at[x]=at[y];
                at[y]=temp;
                temp=et[x];
                et[x]=et[y];
                et[y]=temp;
                strcpy(t,pn[x]);
                strcpy(pn[x],pn[y]);
                strcpy(pn[y],t);
            }
        }
        pj++;
	}
   printf("\n\nAll Process completed the execution.\n");    
        
    printf("\nCalculating average waiting time");    
    for(i=0; i<5; i++)
	{
		printf(".");
		sleep(1);
	}
	printf("\n");
    printf("\nAverage waiting time is : %f",awt);
    printf("\n\nCalculating average turnaroundtime time");    
    for(i=0; i<5; i++)
	{
		printf(".");
		sleep(1);
	}
	printf("\n");    
    printf("\nAverage turnaroundtime is : %f",ata);
    //getch();
}
