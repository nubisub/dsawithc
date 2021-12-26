# Tipe Data Dan Array Pada C

1.  `sizeof()` adalah sebuah operator untuk mengetahui jumlah memori (byte) yang diperlukan oleh suatu tipe data pada bahasa C. Gunakan `sizeof()` untuk mengetahui ukuran memori pada berbagai tipe data pada bahasa pemrograman C, seperti `char, int, float, double`. Catat hasil yang Anda dapatkan. Bandingkan dengan hasil yang didapatkan oleh teman-teman Anda. [Diskusikan apakah yang menyebabkan hasil yang didapatkan berbeda-beda.](https://www.tutorialspoint.com/sizeof-operator-in-c)
2. Amati output yang dihasilkan. Jelaskan mengapa bisa terjadi perubahan demikian pada
nilai x maupun y.
    ```c
        /* Aturan Scope pada Bahasa C */
        #include <stdio.h>
        int main()
        {
            {
                  int x = 10, y = 20; //Global
                 {
                 printf("x = %d, y = %d\n", x, y);
                 {
                    int y = 40; //local
                    x++;
                    y++;
                    printf("x = %d, y = %d\n", x, y);
                }
                printf("x = %d, y = %d\n", x, y);
            }
        }
        system("pause");
        return 0;
    }
    ```

3.  [Buatlah program untuk menginput nilai elemen-elemen Matriks A berukuran 3x4 dan mencetak Matriks A tersebut. Contoh ouput sebagai berikut.](penugasan3.c)
    ```
    1 3 4 5
    2 4 6 8
    3 5 7 9
    ```
