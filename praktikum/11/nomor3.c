// include
#include <stdio.h>

// linked list char 50 and int
typedef struct node
{
    char nama[50];
    int nim;
    struct node *next;
} node;
// insert
void insert(node **head, char nama[], int nim)
{
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->nama, nama);
    new_node->nim = nim;
    new_node->next = *head;
    *head = new_node;
}
// print
void print(node *head)
{
    int i = 1;
    node *current = head;
    while (current != NULL)
    {
        printf("%d %s %d\n", i, current->nama, current->nim);
        current = current->next;
        i++;
    }
}
// search nama
node *search_nama(node *head, char nama[])
{
    node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->nama, nama) == 0)
        {
            printf("NIM : %d\n", current->nim);
            return current;
        }
        current = current->next;
    }
    printf("Not Found\n");
    return NULL;
}

// main
int main()
{
    node *head = NULL;
    // menu
    int pilih;
    char nama[50];
    int nim;
    do
    {
        system("cls");
        printf("1. Insert\n");
        printf("2. Print\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:

            printf("Nama : ");
            scanf("%s", nama);
            printf("NIM : ");
            scanf("%d", &nim);
            insert(&head, nama, nim);
            break;
        case 2:
            print(head);
            break;
        case 3:
            printf("Nama : ");
            scanf("%s", nama);
            search_nama(head, nama);
            break;

        case 4:
            break;
        default:
            printf("Pilihan tidak ada\n");
        }
        printf("\n");
        printf("Press Enter to continue...");
        getch();
    } while (pilih != 4);
    return 0;
}
