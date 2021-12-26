// include
#include <stdio.h>
#include <stdlib.h>

// struct int, char nama[50], int nilai
typedef struct
{
    int nim;
    char nama[50];
    int nilai;
} data;
// input data
void input(data *a)
{
    printf("NIM : ");
    scanf("%d", &a->nim);
    printf("Nama : ");
    scanf("%s", a->nama);
    printf("Nilai : ");
    scanf("%d", &a->nilai);
}
// output data
void output(data a)
{

    printf("%d -- ", a.nim);
    printf("%s -- ", a.nama);
    printf("%d\n", a.nilai);
}
// main function
int main()
{
    // variable
    data mahasiswa[100];
    // menu
    int pilih, i, j;
    // looping
    while (1)
    {
        printf("\n\n");
        printf("1. Input Data\n");
        printf("2. Sort NIM\n");
        printf("3. Sort Nilai\n");
        printf("4. Sort Nama\n");
        printf("5. Print Data\n");
        printf("6. Exit\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        system("cls");
        switch (pilih)
        {
        case 1:
            printf("\n");
            printf("Data ke-%d\n", i + 1);
            input(&mahasiswa[i]);
            i++;
            printf("\nData berhasil diinput\n");
            printf("Press Enter...");
            getch();
            break;
        case 2:

            for (j = 0; j < i; j++)
            {
                for (int k = 0; k < i - 1; k++)
                {
                    if (mahasiswa[k].nim > mahasiswa[k + 1].nim)
                    {
                        data temp = mahasiswa[k];
                        mahasiswa[k] = mahasiswa[k + 1];
                        mahasiswa[k + 1] = temp;
                    }
                }
            }
            printf("Data berhasil diurutkan\n");
            printf("Press Enter...");
            getch();
            break;
        case 3:
            for (j = 0; j < i; j++)
            {
                for (int k = 0; k < i - 1; k++)
                {
                    if (mahasiswa[k].nilai > mahasiswa[k + 1].nilai)
                    {
                        data temp = mahasiswa[k];
                        mahasiswa[k] = mahasiswa[k + 1];
                        mahasiswa[k + 1] = temp;
                    }
                }
            }
            printf("Data berhasil diurutkan\n");
            printf("Press Enter...");
            getch();
            break;
        case 4:
            for (j = 0; j < i; j++)
            {
                for (int k = 0; k < i - 1; k++)
                {
                    if (strcmp(mahasiswa[k].nama, mahasiswa[k + 1].nama) > 0)
                    {
                        data temp = mahasiswa[k];
                        mahasiswa[k] = mahasiswa[k + 1];
                        mahasiswa[k + 1] = temp;
                    }
                }
            }
            printf("Data berhasil diurutkan\n");
            printf("Press Enter...");
            getch();
            break;

        case 5:
            printf("\n");
            printf("NIM -- Nama -- Nilai\n\n");

            for (j = 0; j < i; j++)
            {
                output(mahasiswa[j]);
            }
            printf("\nPress Enter...");
            getch();
            break;
        case 6:
            exit(0);
        default:
            printf("\n");
            printf("Input salah\n");
            break;
        }
        system("cls");
    }

    return 0;
}