#include<stdio.h>
int main()
{
	int num[5];
	int i,j;
	int length,temp;
	
	
	printf("Enter the count : ");
	scanf("%d",&length);
	printf("Enter Numbers : ");


	for(i=0;i<length;i++)
	{
		scanf("%d",&num[i]);
	}


	for(i=0;i<length;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(num[i]>num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}


	for(i=0;i<length;i++)
	{
		printf("%d\t",num[i]);
	}
	printf("\n");


	return 0;
}
