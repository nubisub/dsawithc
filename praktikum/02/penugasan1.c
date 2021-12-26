#include <stdio.h>
void main()
{
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));
    printf("=====================\n");
    int a = 0;
    double d = 10.21;
    printf("%lu\n", sizeof(a));
    printf("%lu\n", sizeof(d));
    printf("%lu\n", sizeof(a + d));
    printf("=====================\n");
    int arr[] = {1, 2, 3, 4, 7, 98, 0, 12, 35, 99, 14};
    printf("Number of elements :%lu \n", sizeof(arr) / sizeof(arr[0]));
    printf("=====================\n");
    system("pause");
    return 0;
}
