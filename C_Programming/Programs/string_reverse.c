#include <stdio.h>
#include <string.h>

void Reverse_word(char name[], int size);
void Reverse_each_word(char name[]);
void Reverse_word_order(char name[]);

int main() {
    char name[50], original[50];
    int size;
    int choise;

    printf("Enter the string: ");
    scanf("%49[^\n]", name);

    strcpy(original, name);
    size = strlen(name);

    do {
        printf("\n1. Print the string\n");
        printf("2. Reverse the entire string\n");
        printf("3. Reverse each word\n");
        printf("4. Reverse the order of words\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choise);

        switch (choise) {
            case 1:
                printf("The string is: %s\n", original);
                break;

            case 2:
                strcpy(name, original);
                Reverse_word(name, size);
                printf("Reversed string: %s\n", name);
                break;

            case 3:
                strcpy(name, original);
                Reverse_each_word(name);
                printf("Reversed each word: %s\n", name);
                break;

            case 4:
                strcpy(name, original);
                Reverse_word_order(name);
                printf("Reversed word order: %s\n", name);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Error number. Try again.\n");
        }

    } while (choise != 5);

    return 0;
}

void Reverse_word(char name[], int size) {
    int i;
    char temp;

    for (i = 0; i < size / 2; i++) {
        temp = name[i];
        name[i] = name[size - i - 1];
        name[size - i - 1] = temp;
    }
}

void Reverse_each_word(char name[]) {
    int i, start = 0, end;
    char temp;
    int size = strlen(name);

    for (i = 0; i <= size; i++) {
        if (name[i] == ' ' || name[i] == '\0') {
            end = i - 1;

            while (start < end) {
                temp = name[start];
                name[start] = name[end];
                name[end] = temp;

                start++;
                end--;
            }

            start = i + 1;
        }
    }
}

void Reverse_word_order(char name[]) {
    int i, start = 0, end;
    char temp;
    int size = strlen(name);

    Reverse_word(name, size);

    for (i = 0; i <= size; i++) {
        if (name[i] == ' ' || name[i] == '\0') {
            end = i - 1;

            while (start < end) {
                temp = name[start];
                name[start] = name[end];
                name[end] = temp;

                start++;
                end--;
            }

            start = i + 1;
        }
    }
}




/*


Enter the string: Dasari Komal Rao

Reversed string: oaR lamoK irasaD

Reversed each word: irasaD lamoK oaR

Reversed word order: Rao Komal Dasari




Enter the string: Dasari Komal Rao

1. Print the string
2. Reverse the entire string
3. Reverse each word
4. Reverse the order of words
5. Exit
Enter your choice: 2
Reversed string: oaR lamoK irasaD

1. Print the string
2. Reverse the entire string
3. Reverse each word
4. Reverse the order of words
5. Exit
Enter your choice: 3
Reversed each word: irasaD lamoK oaR

1. Print the string
2. Reverse the entire string
3. Reverse each word
4. Reverse the order of words
5. Exit
Enter your choice: 4
Reversed word order: Rao Komal Dasari

1. Print the string
2. Reverse the entire string
3. Reverse each word
4. Reverse the order of words
5. Exit
Enter your choice: 5
Exiting program...




*/
