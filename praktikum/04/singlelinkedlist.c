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
    ptrnode head = NULL;
    struct node node_dua;
    ptrnode dua = &node_dua;
    ptrnode tiga = NULL;
    ptrnode empat = NULL;
    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));

    head = (ptrnode)malloc(sizeof(struct node));
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

    printf("Isi dari linked list : \n");
    struct node *n = head;
    while (n != NULL)
    {
        printf("%d\n", n->value);
        n = n->next;
    }

    ptrnode insert_head(ptrnode head, int nilai)
    {
        ptrnode new_node = createNode(nilai);
        new_node->next = head;
        head = new_node;
        return (head);
    }

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

    ptrnode remove_first(ptrnode head)
    {
        if (head == NULL)
            return;

        ptrnode first = head;
        head = head->next;
        first->next = NULL;

        free(first);

        return (head);
    }

    ptrnode remove_last(ptrnode head)
    {
        if (head == NULL)
            return;

        ptrnode tail = head;
        ptrnode prevtail = NULL;
        while (tail->next != NULL)
        {
            prevtail = tail;
            tail = tail->next;
        }

        prevtail->next = NULL;
        free(tail);
        return (head);
    }

    ptrnode remove_middle(ptrnode head, int nilai)
    {
        ptrnode cursor = head;
        while (cursor != NULL)
        {
            if (cursor->next->value == nilai)
                break; //keluar dari iterasi
            cursor = cursor->next;
        }
        if (cursor != NULL)
        {
            ptrnode tmp = cursor->next;
            cursor->next = tmp->next;
            tmp->next = NULL;
            free(tmp);
        }
    }

    ptrnode dispose(ptrnode head)
    {
        if (head == NULL)
            return;

        while (head != NULL)
        {
            ptrnode tmp = head;
            head = head->next;

            tmp->next = NULL;
            free(tmp);
        }

        printf(" semua node telah dihapus\n ");
        return (head);
    }
}