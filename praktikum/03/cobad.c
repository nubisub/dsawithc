#include <stdio.h>
struct bio
{
    char nama[20];
};

void main()
{
    struct bio mhs[2];
    int w = 1;
    tambah(mhs[1]);
    fgets(mhs[w].nama, sizeof(mhs->nama), stdin);

    printf("data %s", mhs[w].nama);
}
void tambah(w)
{
    struct bio mhs[100];

    scanf("%s", &mhs[1].nama);
}
