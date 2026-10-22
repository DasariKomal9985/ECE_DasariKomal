#include <stdio.h>

int main()
{
    int arr[100];
    int size, pos, element;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter element: ");
    scanf("%d", &element);

    for (int i = size; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = element;
    size++;

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
