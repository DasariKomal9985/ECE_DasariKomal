#include <stdio.h>

int main(void)
{
    FILE *fp;
    int data = 100;
    int value = 0;

    fp = fopen("data.bin", "wb");

    if (fp == NULL)
    {
        printf("File open failed\n");
        return 1;
    }

    fwrite(&data, sizeof(data), 1, fp);

    fclose(fp);

    fp = fopen("data.bin", "rb");

    if (fp == NULL)
    {
        printf("File open failed\n");
        return 1;
    }

    fread(&value, sizeof(value), 1, fp);

    printf("Value = %d\n", value);

    fclose(fp);

    return 0;
}
