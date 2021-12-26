#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;         //value
    struct node *next; //penunjuknya
};

typedef struct node *ptrnode;

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

    ptrnode createNode(int nilai)
    {
        ptrnode p;
        p = (ptrnode)malloc(sizeof(struct node));
        p->value = nilai;
        p->next = NULL;
        return (p);
    }
    ptrnode lima = createNode(50);
    empat->next = lima;

    printf("\nIsi dari linked list : ");
    struct node *n = head;
    while (n != NULL)
    {
        printf("%d, ", n->value);
        n = n->next;
    }

    //Insert Kiri

    ptrnode insert_head(ptrnode head, int nilai)
    {
        ptrnode new_node = createNode(nilai);
        new_node->next = head;
        head = new_node;
        return (head);
    }

    // head = insert_head(head, 99);

    ptrnode insert_tail(ptrnode head, int nilai)
    {
        /* iterasi mencari node terakhir*/
        ptrnode tail = head;
        while (tail->next != NULL)
            tail = tail->next;

        /* buat node baru */
        ptrnode new_node = createNode(nilai);
        tail->next = new_node;
        return (head);
    }

    ptrnode insert_after(ptrnode head, int nilai, int prev_nilai)
    {
        /* cari node sebelumnya, starting from the first node*/
        ptrnode cursor = head;
        while (cursor->value != prev_nilai)
            cursor = cursor->next;

        ptrnode new_node = createNode(nilai);
        new_node->next = cursor->next;
        cursor->next = new_node;

        return (head);
    }
    // insert_after(head, 76, 10);

    ptrnode insert_before(ptrnode head, int nilai, int next_nilai)
    {
        if (head->value == next_nilai)
            head = insert_head(head, nilai);
        else
        {
            ptrnode cursor, prevcursor;
            cursor = head;
            do
            {
                prevcursor = cursor;
                cursor = cursor->next;
            } while (cursor->value != next_nilai);

            ptrnode new_node = createNode(nilai);
            new_node->next = cursor;
            prevcursor->next = new_node;
        }
        return (head);
    }
    // insert_before(head, 69, 50);

    int c;
    printf("\n\nmasukkan nilai yang akan diinput = ");
    scanf("%d", &c);

    ptrnode temp = head;
    ptrnode temp2 = temp;

    do
    {
        temp2 = temp;
        temp = temp->next;
        if (temp2->next == NULL)
        {
            break;
        }

    } while (c >= temp->value);

    if (temp2->value <= head->value)
    {
        head = insert_head(temp2, c);
    }
    else
    {
        insert_after(head, c, temp2->value);
    }

    printf("\nIsi dari linked list : ");
    struct node *q = head;
    while (q != NULL)
    {
        printf("%d, ", q->value);
        q = q->next;
    }

}