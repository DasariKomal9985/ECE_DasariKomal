// To find the second largest elemnt in the array 





#include<stdio.h>
int main()
{
    int arr[] = {1,2,8,3,9,21};
    int b = sizeof(arr)/sizeof(arr[0]);
    int a = 0;
    int c = 0;
    
    for(int i=0; i<b; i++)
    {
        if(arr[i] > a)
        {
            c = a;
            a = arr[i];
        }
        else if((arr[i] > c) && ( c < a))
        {
            c = arr[i];
        }
    }
    printf("Second Largest Element is : %d",c);
    printf("Fisrt Largest Element is : %d",a);
    return 0;
}




/*

output

Current element		Largest (a)	Second largest (c)
1				1		0
2				2		1
8				8		2
3				8		3
21				21		8
9				21		9


*/
