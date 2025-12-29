#include<stdio.h>
int main()
{
    int a;
    int sum =0;
    printf("Enter the value  :");
    scanf("%d",&a);
    printf("Perfect square numberes from 1 and %d are:\n",a);
    for(int i=1;i*i<=a;i++)
    {
        printf("%d ",i*i);
        sum++;
    }
    printf("\nTotal count of perfect squares: %d\n",sum);
    return 0;
    
}