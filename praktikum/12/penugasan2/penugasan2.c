// include
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 //ukuran maksimum array
// input array function
void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Masukkan nilai ke-%d : ", i + 1);
        scanf("%d", &arr[i]);
    }
}
// insertionsort function
void insertionSortAsc(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void insertionSortDesc(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sortasc(int data[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
            if (data[i] < data[min_idx])
                min_idx = i;
        swap(&data[min_idx], &data[step]);
    }
}
void selection_sortdesc(int data[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
            if (data[i] > data[min_idx])
                min_idx = i;
        swap(&data[min_idx], &data[step]);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

mergeDesc(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// merge sort descending
void mergeSortDesc(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortDesc(arr, l, m);
        mergeSortDesc(arr, m + 1, r);
        mergeDesc(arr, l, m, r);
    }
}

void bubbleSortAsc(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void bubbleSortDesc(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
// print array function

// main
int main()
{
    int n, x;
    int arr[MAX];
    char pilih;
    printf("###PROGRAM SORTING DATA###\n");

    printf("Pilih pengurutan Naik/Turun(N/T): ");
    scanf("%c", &pilih);
    printf("Input Jumlah data : ");
    scanf("%d", &n);

    printf("Metode Sorting yang tersedia\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Bubble Sort\n");
    printf("\nPilih Metode Sorting (1/2/3/4): ");
    scanf("%d", &x);

    printf("\nInput Data Anda: \n");
    inputArray(arr, n);
    switch (x)
    {
    case 1:
        if (pilih == 'N')
        {
            insertionSortAsc(arr, n);
        }
        else if (pilih == 'T')
        {
            insertionSortDesc(arr, n);
        }
        else
        {
            printf("Input salah");
        }
    case 2:
        if (pilih == 'N')
        {
            selection_sortasc(arr, n);
        }
        else if (pilih == 'T')
        {
            selection_sortdesc(arr, n);
        }
        else
        {
            printf("Input salah");
        }

        break;
    case 3:
        if (pilih == 'N')
        {
            mergeSort(arr, 0, n - 1);
        }
        else if (pilih == 'T')
        {
            mergeSortDesc(arr, 0, n - 1);
        }
        else
        {
            printf("Input salah");
        }
        break;
    case 4:
        if (pilih == 'N')
        {
            bubbleSortAsc(arr, n);
        }
        else if (pilih == 'T')
        {
            bubbleSortDesc(arr, n);
        }
        else
        {
            printf("Input salah");
        }
        break;
    default:
        printf("Input salah, data belum diurutkan");

        break;
    }
    printf("\nData Akhir: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
