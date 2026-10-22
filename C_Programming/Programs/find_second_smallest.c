#include <stdio.h>

int main()
{
    int arr[10];
    int size;
    int i;
    printf("Enter Size : ");
    printf("%d",size);
    printf("Enter Elements : ");
    for(i=0;i<size;i++)
    {
    scanf("%d",arr);
    }
    int a=arr[0];
    int b=0;
    
    for(i=0; i<size; i++)
    {
        if(arr[i] < a)
        {
            b = a;
            a = arr[i];
        }
        else if(arr[i] < b && b > a)
        {
            b = arr[i];
        }
    }
    printf("first smallest : %d\n",a);
    printf("second smallest : %d\n",b);
    return 0;
}
