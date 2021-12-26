#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node *ptrnode;

ptrnode createNode(int nilai)
{
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;

    return (p);
}

ptrnode insertNode(ptrnode head, int nilai)
{
    ptrnode new_node = createNode(nilai);
    //head masih dalam kondisi NULL

    if (head == NULL)
    {
        head = new_node;
        return (head);
    }
    //mencari node yang berada tepat setelah node baru
    ptrnode cursor = head;
    ptrnode precursor;

    while ((cursor->value < nilai) && (cursor->next != NULL))
    {
        precursor = cursor;
        cursor = cursor->next;
    }

    //node baru menjadi head
    if (cursor->prev == NULL)
    {

        if (head->value > nilai)
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        else
        {
            head->next = new_node;
            new_node->prev = head;
            head = head;
        }
    }
    else if ((cursor->next == NULL)&&(nilai>cursor->value))
    {
        cursor->next = new_node;
        new_node->prev = cursor;
    }

    else
    {
        precursor->next = new_node;
        new_node->prev = precursor;
        cursor->prev = new_node;
        new_node->next = cursor;
    }
    return (head);
}

void tampilNode(ptrnode head)
{
    int i = 1, j = 1;
    ptrnode n = head;
    ptrnode temp;
    system("cls");
    printf("======================\n");
    printf("     Nilai Menaik     \n");
    printf("======================\n");
    while (n != NULL)
    {
        printf(" nilai ke-%d = %d \n", i, n->value);
        temp = n;
        n = n->next;
        i++;
    };
    printf("\n\n");

    printf("======================\n");
    printf("     Nilai Menurun     \n");
    printf("======================\n");

    while (temp != NULL)
    {
        printf(" nilai ke-%d = %d \n", j, temp->value);
        temp = temp->prev;
        j++;
    };
    printf("\n\n");
}
void menu()
{
    printf("\n\n Silahkan pilih menu:\n");
    printf(" 1. Insert Node\n");
    printf(" 2. Show List\n");
    printf(" 3. Exit\n\n");
}
void main()
{
    int pilih, value;
    ptrnode head = NULL;
    int i = 1;

    do
    {

        menu();
        do
        {
            printf("Pilihan Anda: ");
            scanf("%d", &pilih);
        } while ((pilih < 1) || (pilih > 4));

        switch (pilih)
        {
        case 1:
            printf("Input Nilai Ke-%d = ", i);
            i = i+1;
            scanf("%d", &value);
            head = insertNode(head, value);
            break;
        case 2:
            tampilNode(head);
        }
        system("pause");

        system("cls");
    } while (pilih != 3);
}
