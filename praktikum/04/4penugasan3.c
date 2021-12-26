#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int value;
    char nama[50];
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

    head->value = 20988212;
    head->next = dua;
    strcpy(head->nama, "andy warhol");
    dua->value = 20982312;
    dua->next = tiga;
    strcpy(dua->nama, "Hector Salamanca");
    tiga->value = 20388212;
    tiga->next = empat;
    strcpy(tiga->nama, "Gustavo Fring");
    empat->value = 20988216;
    empat->next = lima;
    strcpy(empat->nama, "Hank Schrader");
    lima->value = 20982212;
    lima->next = NULL;
    strcpy(lima->nama, "Skinny Pete");

    printf("===================================\n");
    printf("  NIM\t\t     Nama\n");
    printf("===================================\n");

    struct node *n = head;
    while (n != NULL)
    {
        printf("%d\t%s \n", n->value, n->nama);
        n = n->next;
    }
    printf("\n");
    system("pause");
}