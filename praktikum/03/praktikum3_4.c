#include <stdio.h>;

struct data_tanggal
{
    int tahun;
    int bulan;
    int tanggal;
} ultah;

int main()
{
    //akses dan inisialisasi elemen-elemen struct tanggal
    ultah.tanggal = 28; //ganti dengan tanggal lahir Anda
    ultah.bulan = 7;    //ganti dengan bulan lahir Anda
    ultah.tahun = 1998; //ganti dengan tahun lahir Anda

    printf(" tanggal = % d, bulan = % d, tahun = % d ", ultah.tanggal, ultah.bulan, ultah.tahun);
    return 0;
}