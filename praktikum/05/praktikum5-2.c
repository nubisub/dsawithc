#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node
{
    char nama[30];
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node *ptrnode;
ptrnode createNode(int nilai, char *name)
{
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    strcpy(p->nama, name);
    p->next = NULL;
    p->prev = NULL;

    return (p);
}

ptrnode inserthead(ptrnode head, int nilai, char *name)
{
    ptrnode new_node = createNode(nilai, name);

    head = new_node;
    return (head);
}

ptrnode insertNode(ptrnode head, int nilai, char *name)
{

    ptrnode new_node = createNode(nilai, name);
    ptrnode cursor = head;
    ptrnode precursor;

    while (cursor->next != NULL)
    {
        precursor = cursor;
        cursor = cursor->next;
    }

    cursor->next = new_node;
    new_node->prev = cursor;

    return (head);
}

void tampilNode(ptrnode head)
{
    int i = 1, j = 1;
    ptrnode n = head;
    ptrnode temp;
    system("cls");
    printf("=====================================\n");
    printf("   Nilai             Nama\n");
    printf("=====================================\n");

    while (n != NULL)
    {
        printf("    %d \t        %s  \n", n->value, n->nama);
        n = n->next;
        i++;
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
    char name[30];
    ptrnode head;
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
            printf("Input Mahasiswa ke-%d\n", i);
            printf("Nama   = ");
            // scanf("%s", &name);
            getchar();
            fgets(name, sizeof(name), stdin);
            printf("Nilai  = ");
            scanf("%d", &value);
            if (i == 1)
            {
                head = inserthead(head, value, name);
            }
            else
            {
                head = insertNode(head, value, name);
            }

            i = i + 1;

            break;
        case 2:
            tampilNode(head);
        }
        system("pause");

        system("cls");
    } while (pilih != 3);
}
