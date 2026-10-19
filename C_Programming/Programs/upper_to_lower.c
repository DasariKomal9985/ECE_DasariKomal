#include<stdio.h>
void call_uppercase(char letters[])
{
	int i = 0;
	while(letters[i] != '\0')
	{
		if(letters[i]>='a' && letters[i]<='z')
		{
			letters[i] = letters[i] - 32;
		}
		i++;
	}
	printf("The String is Upper Case : %s",letters);
	return;
}
void call_lowercase(char letters[])
{
	int i = 0;
	while(letters[i] != '\0')
	{
		if(letters[i]>='A' && letters[i]<='Z')
		{
			letters[i] = letters[i] + 32;
		}
		i++;
	}
	printf("The String is Lower Case : %s",letters);
}
int main()
{
	char letters[50];
	int choise;
	printf("Enter the String : ");
	scanf("%49[^\n]",letters);
	printf("Enter the Case : \n1.) Upper_Case\n2.) Lower_Case\n ");
	scanf("%d",&choise);
	switch(choise)
	{
		case 1: call_uppercase(letters);
			break;
		case 2: call_lowercase(letters);
			break;
		default : printf("Original String is : %s",letters);
	}
	printf("\n");
	return 0;
}



/*

Enter the String : dasari komal
Enter the Case : 
1.) Upper_Case
2.) Lower_Case
 1
The String is Upper Case : DASARI KOMAL



*/
