#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;         //value
    struct node *next; //penunjuknya
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

void main()
{

    struct node node_dua;
    ptrnode dua = &node_dua;

    ptrnode head = NULL;
    ptrnode tiga = NULL;
    ptrnode empat = NULL;
    
    head = (ptrnode)malloc(sizeof(struct node));
    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));

    head->value = 10;
    head->next = dua;

    dua->value = 20;
    dua->next = tiga;

    tiga->value = 30;
    tiga->next = empat;

    empat->value = 40;
    empat->next = NULL;
    
    ptrnode lima = createNode(50);
    empat->next = lima;

    printf("Isi dari linked list : \n");
    struct node *n = head;
    while (n != NULL)
    {
        printf("%d\n", n->value);
        n = n->next;
    }
}