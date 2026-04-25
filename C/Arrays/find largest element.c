#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],max=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    printf("Largest number in array is %d",max);
    return 0;
}