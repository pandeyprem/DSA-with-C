#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,n;
    clrscr();
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    printf("\nPyramid of * with %d rows:\n",n);
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=0;j<n-i;j++)
        printf(" ");
        for(j=0;j<2*i-1;j++)
        printf("*");
        getch();
    }
}
