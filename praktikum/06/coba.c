#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node *item;
item top;

void initialize()
{
    top = NULL;
}
void push(int value)
{
    item new_node;
    new_node = (item)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}
void pop()
{
    if (top == NULL)
    {
        printf("Belum Input Stack\n");
        return;
    }

    item tmp;
    tmp = top;
    top = top->next;
    free(tmp);
}
void display(item head)
{
    

    if (head == NULL)
    {
            printf("Stack Kosong\n");
    }

    else
    {
        item temp = head;

        printf("%d\n", head->data);
        if (head->next != NULL)
        {
            display(temp->next);
        }
         
    }
}
int main()
{
    initialize();
    pop();
    printf("Isi dari Stack\n");
    display(top);
    push(10);
    push(20);
    push(30);
    push(40);
    printf("Isi dari Stack\n");

    display(top);
}