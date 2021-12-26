#include <stdio.h>
typedef struct node
{
    int data;
    int priority;
    struct node *next;
} Node;

Node *newNode(int d, int p)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

void insert_pq(Node **head, int d, int p)
{
    Node *temp = newNode(d, p);
    if ((*head)->priority > p)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        Node *start = (*head);
        while (start->next != NULL && start->next->priority <= p)
        {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}
void remove_pq(Node **head)
{
    Node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("-\n");
    }
    else
    {
        printf("%d, %d\n", head->data, head->priority);
        display(head->next);
    }
}
int main()
{
    Node *pq = newNode(4, 1);
    insert_pq(&pq, 5, 2);
    insert_pq(&pq, 6, 3);
    insert_pq(&pq, 7, 0);

    display(pq);

    remove_pq(&pq);

    display(pq);

    return 0;
}