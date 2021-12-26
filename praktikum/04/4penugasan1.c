#include <stdio.h>
#include <stdlib.h>

struct simpul
{
    int nilai;
    struct simpul *selanjutnya;
};
typedef struct simpul *pointersimpul;

void main()
{
    pointersimpul head = NULL;
    head = (pointersimpul)malloc(sizeof(struct simpul));

    head->nilai = 10;
    head->selanjutnya = NULL;

    pointersimpul buatsimpul(int input)
    {
        pointersimpul x = (pointersimpul)malloc(sizeof(struct simpul));
        x->nilai = input;
        x->selanjutnya = NULL;
    }
    pointersimpul dua = buatsimpul(20);
    head->selanjutnya = dua;

    pointersimpul tiga = buatsimpul(76);
    dua->selanjutnya = tiga;

    void hitungsimpul(head)
    {
        struct simpul *i = head;
        int j = 1;
        while (i != NULL)
        {
            printf("Nilai node ke-%d = %d\n", j, i->nilai);
            i = i->selanjutnya;
            j = j + 1;
        }
        printf("Total semua node = %d\n", j - 1);
    }
    hitungsimpul(head);
    system("pause");
}
