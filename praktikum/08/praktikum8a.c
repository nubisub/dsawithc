#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
void displayPreorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);    //root
    displayPreorder(node->left);  //subtree kiri
    displayPreorder(node->right); //subtree kanan
}

void displayInorder(struct node *node)
{
    if (node == NULL)
        return;
    displayInorder(node->left);  //subtree kiri
    printf("%d ", node->data);   //root
    displayInorder(node->right); //subtree kanan
}

void displayPostorder(struct node *node)
{
    if (node == NULL)
        return;
    displayPostorder(node->left);  //subtree kiri
    displayPostorder(node->right); //subtree kanan
    printf("%d ", node->data);     //root
}

struct node *insert(struct node *root, int newData)
{
    if (root == NULL)
    {
        root = newNode(newData);
    }
    else

    {
        int is_left = 0;
        struct node *cursor = root;
        struct node *prev = NULL;
        while (cursor != NULL)
        {
            prev = cursor;
            if (newData < cursor->data)
            {
                is_left = 1;
                cursor = cursor->left;
            }
            else if (newData > cursor->data)
            {
                is_left = 0;
                cursor = cursor->right;
            }
        }

        if (is_left == 1)
            prev->left = newNode(newData);
        else
            prev->right = newNode(newData);
    }

    return root;
}

void search_node(struct node *root, int data)
{
    struct node *cursor = root;

    while (cursor->data != data)
    {
        if (cursor != NULL)
        {
            if (data > cursor->data)
            {
                cursor = cursor->right;
            }
            else
            {
                cursor = cursor->left;
            }

            if (cursor == NULL)
            {
                printf("\nNode % d tidak ditemukan ", data);
            }
        }
    }

    printf("\nNode % d ditemukan & ", data);
    return;
}

struct node *delete_node(struct node *root, int deletedData)
{
    if (root == NULL)
        return;

    struct node *cursor;
    if (deletedData > root->data)
        root->right = delete_node(root->right, deletedData);
    else if (deletedData < root->data)
        root->left = delete_node(root->left, deletedData);
    else
    {
        //1 CHILD
        if (root->left == NULL)
        {
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if (root->right == NULL)
        {

            cursor = root->left;
            free(root);
            root = cursor;
        }
        //2 CHILDS NODE
        else
        {
            cursor = root->right;
            while (cursor->left != NULL)
            {
                cursor = cursor->left;
            }
            root->data = cursor->data;
            root->right = delete_node(root->right, cursor->data);
        }
    }
    return root;
}

int main()
{
    struct node *root = newNode(25);

    root = insert(root, 70);
    root = insert(root, 32);
    root = insert(root, 45);
    root = insert(root, 18);
    root = insert(root, 21);
    root = insert(root, 85);
    root = insert(root, 23);
    root = insert(root, 66);
    root = insert(root, 43);
    root = insert(root, 74);
    root = insert(root, 10);
    root = insert(root, 81);
    root = insert(root, 55);

    // root->left = newNode(3);
    // root->left->right = newNode(1);
    // root->left->left = newNode(6);
    // root->left->right->right = newNode(4);
    // root->left->right->left = newNode(7);

    // root->right = newNode(10);
    // root->right->left = newNode(14);
    // root->right->left->right = newNode(13);
    displayPreorder(root);
    printf("\n");
    displayInorder(root);
    printf("\n");
    displayPostorder(root);

    // search_node(root, 6);
    // search_node(root, 100);

    root = delete_node(root, 13);
    root = delete_node(root, 3);
    printf("\n");
    displayInorder(root);

    system("pause");
    return 0;
}