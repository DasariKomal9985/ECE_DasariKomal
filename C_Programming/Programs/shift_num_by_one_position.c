#include<stdio.h>
int main()
{
	int num[5];
	int i;
	int length;
	int temp;
	printf("Enter numbers size : ");
	printf("\n");
	scanf("%d",&length);
	printf("Enter Numbers : ");
	printf("\n");
	for(i=0;i<length;i++)
	{
		scanf("%d",&num[i]);
	}
	printf("Actual position of all elements : \n");
	for(i=0;i<length;i++)
	{
		printf("%d\t",num[i]);
	}
	printf("\n");
	temp = num[length - 1];
	printf("Temp value is : %d\n",temp);
	for(i=length - 1;i > 0;i--)
	{
		num[i] = num[ i - 1 ];
	}
	num[0] = temp;
	printf("\n");
	printf("Shifted by one position by right is : \n");
	for(i=0;i<length;i++)
	{
		printf("%d\t",num[i]);
	}
	printf("\n");
	return 0;
}
