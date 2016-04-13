#include<stdio.h>
int n,a[10],i,x[10],d;
void subset(int,int,int);
int main()
{
    int sum=0;
    printf("Enter the no of elements\n");
    scanf("%d",&n);

    printf("Enter the %d elements\n",n);

    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

     printf("Enter the required sum\n");
     scanf("%d",&d);

     for(i=1;i<=n;i++)
            sum+=a[i];

    if(sum<d || a[1]>d)
        printf("Subset is not possible\n");
    else
    {
        printf("Possible Subset are\n");
        subset(0,1,sum);
    }
    return 0;
}
void subset(int cs,int k,int r)
{
    x[k]=1;
    if((cs+a[k])==d)
    {
        for(i=0;i<=k;i++)
            if(x[i]==1)
                printf("%d\t",a[i]);
            printf("\n");
    }
    else
    {
        if(cs+a[k]+a[k+1]<=d)
            subset(cs+a[k],k+1,r-a[k]);

        if((cs+r-a[k]>=d)&&(cs+a[k+1]<=d))
        {
            x[k]=0;
            subset(cs,k+1,r-a[k]);
        }
    }
}
