#include<stdio.h>
int x[20],count=0;

int place(int k,int i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if((x[j]==i) || abs(x[j]-i)== abs(j-k))
            return 0;
    }
    return 1;
}

void display_soln(int n)
{
    int i,j;
    char cb[50][50];
    count++;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cb[i][j]='x';

    for(i=1;i<=n;i++)
        cb[i][x[i]]='Q';

    printf("The soln %d \n",count);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%c\t",cb[i][j]);
        printf("\n");
    }
    printf("\n");
}

void nqueen(int k,int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
                display_soln(n);
            else
                nqueen(k+1,n);

        }
    }
}

int main()
{
    int n;
    printf("Enter the no of queens\n");
    scanf("%d",&n);

    nqueen(1,n);

    if(count==0)
        printf("No solution for %d queens",n);

    return 0;
}
