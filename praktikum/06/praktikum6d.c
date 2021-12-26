#include <stdio.h>
#include <stdlib.h>

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
    int i, n, l;
    int input;
    ptrnode head;
    head = NULL;
    printf("Program konversi Desimal ke Biner\n\n");
    printf("Masukkan bilangan desimal = ");
    scanf("%d", &input);
    for (n = input; n > 0; n = n / 2)
    {
        l = n % 2;
        head = insertNode(head, l);
    }
    printf("Hasil konversi ke biner   = ");
    while (head != NULL)
    {
        printf("%d", head->value);
        head = view(head);
    }

    printf("\n");
    system("pause");
}