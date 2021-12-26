# Tumpukan/Stack
1. [Modifikasi program tersebut agar bisa juga mengkonversi bilangan bulat negatif.](praktikum6a.c)
    ```c
    #include <stdio.h>
    typedef struct
    {
        int item[50];
        int count;
    } stack;
    //menyiapkan tumpukan kosong
    void initializestack(stack * s)
    {
        s->count = 0;
    }
    //jika tumpukan kosong maka nilai fungsinya 1 (true),
    //jika tidak 0(false)
    int empty(stack * s)
    {
        return (s->count == 0);
    }
    //jika tumpukan sudah full(dlm deklarasi stack, field item
    //adalah array dg jumlah elemen sebanyak 50)maka nilai
    //nilai fungsinya 1, jika tidak 0
    int full(stack * s)
    {
        return (s->count == 49);
    }

    void push(int x, stack *s)
    {
        if (full(s))
            printf(" Bilangan terlalu besar !\n ");
        else
        {
            s->item[s->count] = x;
            ++(s->count);
        }
    }

    int pop(stack * s)
    {
        if (empty(s))
            return (0);
        else
        {
            --(s->count);
            return (s->item[s->count]);
        }
    }

    void main()
    {
        int i, n, l;
        int input;
        stack tumpukan;
        printf("Program konversi Desimal ke Biner\n\n");
        initializestack(&tumpukan);

        printf("Masukkan bilangan desimal = ");
        scanf("%d", &input);

        for (n = input; n > 0; n = n / 2)
        {
            l = n % 2;
            push(l, &tumpukan);
        }

        printf("Hasil konversi ke biner = ");
        if (input == 0)
            printf("0");
        else
            for (i = tumpukan.count; i > 0; i--)
            {
                printf("%d", pop(&tumpukan));
            }
        printf("\n");
        system("pause");
    }
    ```
2. [Buatlah sebuah fungsi konversi, agar fungsi utama/ main dalam program di atas menjadi lebih sederhana.](praktikum6b.c)
3. [Buat program yang dapat mengkonversi bilangan desimal menjadi bilangan oktal.](praktikum6c.c)
4. [Buat program konversi desimal ke biner di atas dengan menggunakan linked list.](praktikum6d.c)