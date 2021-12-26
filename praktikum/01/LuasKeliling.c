#include <stdio.h>

void main()
{
    int p, l;
    system("cls");
    puts("====================================");
    puts(" Luas dan Keliling Persegi Panjang ");
    puts("====================================");

    printf("Panjang  = ");
    scanf("%d", &p);
    printf("Lebar    = ");
    scanf("%d", &l);
    puts("===================");
    printf("Luas     = %d\n", p * l);
    printf("keliling = %d\n", 2 * (p + l));
    puts("===================");

    system("pause");
}