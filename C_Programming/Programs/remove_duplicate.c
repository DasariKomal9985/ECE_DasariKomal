//	Remove Duplicate String






#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];

    printf("Enter the string: ");
    scanf("%99s", a);

    int b = strlen(a);

    for (int i = 0; i < b; i++)
    {
        for (int j = i + 1; j < b; j++)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < b - 1; k++)
                {
                    a[k] = a[k + 1];
                }

                b--;
                a[b] = '\0';
                j--;
            }
        }
    }

    printf("String after removing duplicates: %s\n", a);

    return 0;
}



/*



Before shifting
h


e


l


l


o




a[3] = a[4] copies o over the second l
After shifting
h


e


l


o


o



The effective string is now helo. The last o is a leftover character outside the new length.




Expression	Purpose
i < b	Visit each character
j < b	Check later characters for duplicates
k < b - 1	Shift characters left without reading beyond the last character
b--	Decrease the string's effective length
a[b] = '\0'	Terminate the shortened string
j--	Recheck the position where a character shifted in


Index:      0   1   2   3   4
Character:  h   e   l   o  '\0'
helo

*/
