#include <stdio.h>
int main() {
    int n; 
    scanf("%d",&n);
    int arr[6]={1,2,3,5,6}; 
    int total=n*(n+1)/2;
    for(int i=0;i<n;i++)
    {
       
        total-=arr[i];
        
    }
    printf("Missing: %d\n",total);
    return 0;
}