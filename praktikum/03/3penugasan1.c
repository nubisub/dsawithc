#include <stdio.h>
#include <stdlib.h>

struct biodata
{
    char NIM[10];
    char nama[30];
    char kelas[5];
    int nilai;
};
int main()
{
    int n, p = 1;
    struct biodata mhs[100];

    printf("===========================\n");
    printf("  Program Input Mahasiswa  \n");
    printf("===========================\n");
    printf("Banyaknya Mahasiswa = ");
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        printf("Silakan Input Data Mahasiswa ke-%d\n", i);
        printf("Nama  = ");
        scanf("%s", &mhs[i].nama);
        printf("NIM   = ");
        scanf("%s", &mhs[i].NIM);
        printf("Kelas = ");
        scanf("%s", &mhs[i].kelas);
        printf("Nilai = ");
        scanf("%d", &mhs[i].nilai);
        getchar();
    }
    printf("==================================\n");
    printf("     Nama   -   Kelas - Nilai\n");
    printf("==================================\n");

    for (int i = 1; i <= n; i++)
    {
        printf("%d.  %s\t %s\t %d\n", i, mhs[i].nama, mhs[i].kelas, mhs[i].nilai);
    }

    system("pause");
    return 0;
}