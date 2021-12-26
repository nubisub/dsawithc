#include <stdio.h>
void main()
{
    int matrix[3][4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("baris %d kolom %d = ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
    system("pause");
}