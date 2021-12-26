#include <stdio.h>
int main()
{
    int *p;
    printf("%d\n", &p);
    int a = 10;
    p = &a;
    printf("%d", p);
}