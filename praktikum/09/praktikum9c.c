
#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct node
{
	int data;
	char nama[50];
	struct node *left;
	struct node *right;
	int height;
};

int max(int a, int b);

int height(struct node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct node **createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);

void printLevelOrder(struct node *node)
{
	int rear, front;
	struct node **queue = createQueue(&front, &rear);
	struct node *temp_node = node;

	while (temp_node)
	{
		printf("%s, ", temp_node->nama);

		if (temp_node->left)
			enQueue(queue, &rear, temp_node->left);

		if (temp_node->right)
			enQueue(queue, &rear, temp_node->right);

		temp_node = deQueue(queue, &front);
	}
}

struct node **createQueue(int *front, int *rear)
{
	struct node **queue = (struct node **)malloc(
		sizeof(struct node *) * MAX_Q_SIZE);

	*front = *rear = 0;
	return queue;
}

void enQueue(struct node **queue, int *rear,
			 struct node *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
	(*front)++;
	return queue[*front - 1];
}

struct node *newnode(int data, char *name)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	strcpy(node->nama, name);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return (node);
}

struct node *rightRotate(struct node *y)
{
	struct node *x = y->left;
	struct node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

int getBalance(struct node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct node *insert(struct node *node, int data, char *name)
{
	if (node == NULL)
		return (newnode(data, name));

	if (data < node->data)
		node->left = insert(node->left, data, name);
	else if (data > node->data)
		node->right = insert(node->right, data, name);
	else
		return node;
	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);

	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

struct node *minValueNode(struct Node *node)
{
	struct node *current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

struct Node *deleteNode(struct node *node, int data)
{

	if (node == NULL)
		return node;

	if (data < node->data)
		node->left = deleteNode(node->left, data);

	else if (data > node->data)
		node->right = deleteNode(node->right, data);

	else
	{
		if ((node->left == NULL) || (node->right == NULL))
		{
			struct node *temp = node->left ? node->left : node->right;

			if (temp == NULL)
			{
				temp = node;
				node = NULL;
			}
			else
				*node = *temp;
			free(temp);
		}
		else
		{

			struct node *temp = minValueNode(node->right);

			node->data = temp->data;

			node->right = deleteNode(node->right, temp->data);
		}
	}

	if (node == NULL)
		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && getBalance(node->left) >= 0)
		return rightRotate(node);

	if (balance > 1 && getBalance(node->left) < 0)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && getBalance(node->right) <= 0)
		return leftRotate(node);

	if (balance < -1 && getBalance(node->right) > 0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

int main()
{
	struct node *node = NULL;

	node = insert(node, 1, "Brendant");
	node = insert(node, 2, "Ken");
	node = insert(node, 3, "Mark");
	node = insert(node, 4, "Robber");
	node = insert(node, 5, "Frank");
	node = insert(node, 6, "Max");
	node = insert(node, 7, "Chad");
	node = deleteNode(node, 4);
	printLevelOrder(node);

	return 0;
}
