#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node *ptrnode;

ptrnode createNode(int nilai)
{
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    return (p);
}

ptrnode insertNode(ptrnode head, int nilai)
{

    ptrnode new_node = createNode(nilai);
    new_node->next = head;
}

ptrnode view(ptrnode head)
{
    ptrnode temp = head;
    head = head->next;
    free(temp);
    return (head);
}

void main()
{
    int i, n, l, nilai = 0, p = 0;
    int input;
    ptrnode head;
    head = NULL;
    printf("Program konversi Desimal ke Biner\n\n");
    printf("Masukkan bilangan desimal = ");
    scanf("%d", &input);
    if (input < 0)
    {
        input = abs(input);

        for (n = input; n > 0; n = n / 2)
        {
            l = n % 2;
            if (l == 1)
            {
                l = 0;
            }
            else
            {
                l = 1;
                nilai = nilai + pow(2, p);
            }
            head = insertNode(head, l);
            p = p + 1;
        }

        printf("Hasil konversi ke biner 1st complement  = ");
        while (head != NULL)
        {
            printf("%d", head->value);
            head = view(head);
        }
        int k;
        for (k = nilai + 1; k > 0; k = k / 2)
        {
            l = k % 2;
            head = insertNode(head, l);
        }

        printf("\nHasil konversi ke biner 2st complement  = ");
        while (head != NULL)
        {
            printf("%d", head->value);
            head = view(head);
        }
    }
    else
    {
        for (n = input; n > 0; n = n / 2)
        {
            l = n % 2;
            head = insertNode(head, l);
            p = p + 1;
        }

        printf("Hasil konversi ke biner   = ");
        while (head != NULL)
        {
            printf("%d", head->value);
            head = view(head);
        }
    }
    printf("\n");
    system("pause");
}