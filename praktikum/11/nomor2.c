// include
#include <stdio.h>
// stdlib
#include <stdlib.h>

// struct int and string
struct int_string
{
    int nim;
    char nama[50];
};
// input
void input(struct int_string *a)
{
    printf("NIM : ");
    scanf("%d", &a->nim);
    printf("Nama : ");
    scanf("%s", &a->nama);
}

// view array
void view_array(struct int_string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d. %d - %s\n", i + 1, arr[i].nim, arr[i].nama);
    }
}
// sequential search
int sequential_search(struct int_string arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i].nim == x)
        {
            return i;
        }
    }
    return -1;
}
// sorting
void sorting(struct int_string arr[], int n)
{
    struct int_string temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].nim > arr[j].nim)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// binary search
int binary_search(struct int_string arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid].nim == x)
        {
            return mid;
        }
        else if (arr[mid].nim < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
// main
int main()
{
    // variable
    struct int_string data[50];
    // menu
    int pilih, n, i;
    // loop
    while (pilih != 5)
    {
        printf("\n");
        system("cls");
        printf("1. Input\n2. View\n3. Sequential Search\n4. Binary Search\n5. Exit\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        // clearscreen
        system("cls");
        switch (pilih)
        {
        case 1:
            input(&data[i]);
            i++;
            // success
            printf("Data berhasil diinput\n");
            break;
        case 2:
            view_array(data, i);
            break;
        case 3:
            // search

            printf("\n");
            printf("NIM : ");
            scanf("%d", &n);
            int l = sequential_search(data, i, n);
            if (l != -1)
            {
                printf("Nama : %s\nDitemukan di index ke-%d", data[l].nama, l);
            }
            else
            {
                printf("NIM tidak ditemukan\n");
            }
            break;
        case 5:
            printf("Exit\n");
            break;
        case 4:
            // sorting
            sorting(data, i);
            // binary search
            printf("\n");
            printf("NIM : ");
            scanf("%d", &n);
            int m = binary_search(data, i, n);
            if (m != -1)
            {
                printf("Nama : %s\nDitemukan di index ke-%d", data[m].nama, m);
            }
            else
            {
                printf("NIM tidak ditemukan\n");
            }
            break;
        default:
            printf("Pilih salah\n");
            break;
        }
        // press enter
        printf("\nPress enter to continue...");
        // getchar
        getch();
    }

    return 0;
}