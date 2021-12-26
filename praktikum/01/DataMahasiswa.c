#include <stdio.h>
int main()
{
    int kuis, uts, uas;
    double total;
    char nama[50], nim[20];
    system("cls");
    printf("=========================\n");
    printf("  Nilai Akhir Mahasiswa \n");
    printf("=========================\n");

    //Input
    printf("NIM         = ");
    fgets(nim, sizeof(nim), stdin);
    printf("Nama        = ");
    fgets(nama, sizeof(nama), stdin);
    printf("Nilai Kuis  = ");
    scanf("%d", &kuis);
    printf("Nilai UTS   = ");
    scanf("%d", &uts);
    printf("Nilai UAS   = ");
    scanf("%d", &uas);
    //Output
    printf("=========================\n");
    printf("Nama        = %s", nama);
    printf("NIM         = %s", nim);
    printf("Nilai Kuis  = %d\n", kuis);
    printf("Nilai UTS   = %d\n", uts);
    printf("Nilai UAS   = %d\n", uas);
    printf("Nilai Akhir = %.2g \n", 0.2 * kuis + 0.3 * uts + 0.5 * uas);
    printf("=========================\n");
    system("pause");
}