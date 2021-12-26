#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct node
{
    char nama[30];
    struct node *left;
    struct node *right;
};

struct node *newNode(char *name)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    strcpy(node->nama, name);
    node->left = NULL;
    node->right = NULL;
    return node;
}
void displayPreorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%s, ", node->nama);   //root
    displayPreorder(node->left);  //subtree kiri
    displayPreorder(node->right); //subtree kanan
}

void displayInorder(struct node *node)
{
    if (node == NULL)
        return;
    displayInorder(node->left);  //subtree kiri
    printf("%s, ", node->nama);  //root
    displayInorder(node->right); //subtree kanan
}

void displayPostorder(struct node *node)
{
    if (node == NULL)
        return;
    displayPostorder(node->left);  //subtree kiri
    displayPostorder(node->right); //subtree kanan
    printf("%s, ", node->nama);    //root
}

int main()
{
    struct node *root = newNode("Dwight");

    root->left = newNode("Schrute");
    root->left->right = newNode("Jim");
    root->left->left = newNode("Halpert");
    root->left->right->right = newNode("Stanley");
    root->left->right->left = newNode("Kevin");

    root->right = newNode("Malone");
    root->right->left = newNode("Ryan");
    root->right->left->right = newNode("Howard");

    printf("PreOrder  : ");
    displayPreorder(root);
    printf("\nInOrder   : ");
    displayInorder(root);
    printf("\nPostOrder : ");
    displayPostorder(root);
    printf("\n");


    system("pause");
    return 0;
}