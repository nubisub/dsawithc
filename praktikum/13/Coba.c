#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

struct mahasiswa
{
    char nama[50];
    int nim;
    int nilai;
};

struct mahasiswa insert(struct mahasiswa mhs[max], int *size)
{
    printf("Input Jumlah Data Mahasiswa (max 100) = ");
    scanf("%d", size);
    for (int j = 0; j < *size; j++)
    {
        printf("Mahasiswa %d\n", j+1);
        printf("Nama   : "); scanf("%s", &mhs[j].nama);
        printf("NIM    : "); scanf("%d", &mhs[j].nim);
        printf("Nilai  : "); scanf("%d", &mhs[j].nilai);
        printf("\n");
    }
    return mhs[max];
}

void printlist(struct mahasiswa *mhs, int size)
{
    for (int j = 0; j < size; j++)
    {
        printf("Mahasiswa %d\n", j+1);
        printf("Nama   : %s\n", mhs[j].nama);
        printf("NIM    : %d\n", mhs[j].nim);
        printf("Nilai  : %d\n\n", mhs[j].nilai);
    }
    printf("\n");
}


void swap(struct mahasiswa *a, struct mahasiswa *b)
{
    struct mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sortNIM(struct mahasiswa *mhs, int size)
{
    for(int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for(int i = step +1;i<size;i++)
            if(mhs[i].nim < mhs[min_idx].nim)
                min_idx = i;

        swap(&mhs[min_idx],&mhs[step]);
    }
}

void selection_sortNama(struct mahasiswa *mhs, int size)
{
    for(int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for(int i = step +1;i<size;i++)
            if(strcmp(mhs[i].nama,mhs[min_idx].nama)<0)
                min_idx = i;

        swap(&mhs[min_idx],&mhs[step]);
    }
}

void search_nama(struct mahasiswa *mhs, int n, char *x)
{
    int i;
    printf("%s",x);
    for (i = 0; i < n; i++)
    {
        if (strcmp(mhs[i].nama, x) == 0)
        {
            printf("\nNama : %s\n", mhs[i].nama);
            printf("NIM : %d\n", mhs[i].nim);
            printf("Nilai : %d\n", mhs[i].nilai);
            return;
        }
    }
        printf("Data tidak tersedia");
}

void search_nim(struct mahasiswa *mhs, int n, int x)
{
    for(int i = 0; i < n; i++)
        if(mhs[i].nim == x)
        {
            printf("Data ditemukan" );
            printf("\nNama   : %s\n", mhs[i].nama);
            printf("NIM    : %d\n", mhs[i].nim);
            printf("Nilai  : %d\n\n", mhs[i].nilai);
            return;
        }
        printf("Data tidak tersedia");
}

void main()
{
    int hasil, size, choice, c, cariNIM;
    char cariNama;
    struct mahasiswa mhs[max];
    size = -1;

    do
    {
        printf("#####PROGRAM DATA MAHASISWA#####\n\n");
        printf("MENU-:"
               "\n1. Insert Data"
               "\n2. Sorting Nama"
               "\n3. Sorting NIM"
               "\n4. Searcing Nama"
               "\n5. Searcing NIM"
               "\n6. Tampilkan Data"
               "\n\nPlease enter your choice-:");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                    insert(mhs, &size);
                    break;
            case 2:
                    selection_sortNama(mhs, size);
                    printf("Data berhasil di Sorting");
                    printlist(mhs, size);
                    break;

            case 3:
                    selection_sortNIM(mhs, size);
                    printf("Data berhasil di Sorting");
                    printlist(mhs, size);
                    break;

            case 4:
                    printf("Masukan Nama yang ingin dicari : "); scanf("%s", &cariNama);
                    search_nama(mhs,size,cariNama);
                    break;

            case 5:
                    printf("Masukan NIM yang ingin dicari : "); scanf("%d", &cariNIM);
                    search_nim(mhs,size,cariNIM);
                    break;

            case 6 :
                printlist(mhs,size);
                break;
            default:
                printf("Wrong Input\n");

        }

        printf("\nDo you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    }
    while(c == 1);

    getchar();
}
