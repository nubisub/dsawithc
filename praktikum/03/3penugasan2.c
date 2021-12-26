#include <stdio.h>
typedef struct
{
    int *nilai;
} struktur;

void main()
{
    struktur mhs;
    struktur mhs1;
    int a, b;

    printf("Masukkan Angka 1 = ");
    scanf("%d", &a);
    printf("Masukkan Angka 2 = ");
    scanf("%d", &b);
    mhs.nilai = &a;
    mhs1.nilai = &b;
    printf("=========================\n");
    printf("     Setelah Ditukar     \n");
    printf("=========================\n");
    tukar(mhs.nilai, mhs1.nilai);
    printf("Angka 1 = %d\n", *mhs.nilai);
    printf("Angka 2 = %d\n", *mhs1.nilai);
    system("pause");
}
void tukar(int *value, int *a)
{
    int b = *value;
    *value = *a;
    *a = b;
}