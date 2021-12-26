#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node *ptrnode;

void main()
{

    struct node node_dua;
    ptrnode dua = &node_dua;

    ptrnode head = (ptrnode)malloc(sizeof(struct node));
    ptrnode tiga = (ptrnode)malloc(sizeof(struct node));
    ptrnode empat = (ptrnode)malloc(sizeof(struct node));
    ptrnode lima = (ptrnode)malloc(sizeof(struct node));

    head->value = 1;
    head->next = dua;
    dua->value = 2;
    dua->next = tiga;
    tiga->value = 3;
    tiga->next = empat;
    empat->value = 4;
    empat->next = lima;
    lima->value = 5;
    lima->next = NULL;

    printf("\nIsi dari linked list : ");
    struct node *n = head;
    while (n != NULL)
    {
        printf("%d, ", n->value);
        n = n->next;
    }

    struct node *sebelum = NULL;
    struct node *setelah = NULL;
    struct node *current = head;
    while (current != NULL)
    {
        setelah = current->next;
        current->next = sebelum;
        sebelum = current;
        current = setelah;
    }
    head = sebelum;
    printf("\nIsi dari linked list : ");
    struct node *q = head;
    while (q != NULL)
    {
        printf("%d, ", q->value);
        q = q->next;
    }
    printf("\n");
    system("pause");
}