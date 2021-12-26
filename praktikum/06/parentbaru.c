#include <stdio.h>
#include <stdlib.h>

// structure of a stack node
struct node
{
    char data;
    struct node *next;
};

typedef struct node *ptrnode;

void main()
{
    char input[50];
    int i = 0;
    ptrnode head;
    head = NULL;
    printf("Input = ");
    scanf("%s", &input);
    while (input[i])
    {
        printf("%c", input[i]);

        if (input[i] == '{' || input[i] == '(' || input[i] == '[')
        {
            // Push
            insertNode(head, input[i]);
        }
        else if (input[i] == '}' || input[i] == ')' || input[i] == ']')
        {
            // Check
        }

        i++;
    }
}

// ptrnode createNode(char *y)
// {
//     ptrnode p;
//     p = (ptrnode)malloc(sizeof(struct node));
//     strcpy(p->data, y);
//     p->next = NULL;
//     return (p);
// }

ptrnode insertNode(ptrnode head, char *y)
{
    // ptrnode new_node = createNode(y);
    // new_node->next = head;
    printf("%c", y);
}
