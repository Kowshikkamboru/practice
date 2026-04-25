#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int first=INT_MIN,second=INT_MIN;// also to eliminate <limits.h> can assign INT_MIN to 0.
     for(int i=0;i<n;i++)
    {
        if(arr[i]>first)
        {
            second=first;
            first=arr[i];
        }
        else if(arr[i]>second && arr[i]!=first)
        {
            second=arr[i];
        }
        else
            printf("Invaild input");
    }

    printf("Second largest number :%d",second);
    return 0;
}