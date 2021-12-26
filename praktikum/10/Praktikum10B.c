#include <stdio.h>
#include <stdlib.h>

struct item
{
    int key;
    int value;
    struct node *next;
};

struct hashtable_item
{
    int flag;
    /* flag = 0 : Tidak ada data
    * flag = 1 : Ada data
    * flag = 2 : Sebelumnya ada datanya */
    struct item *data;
};

struct hashtable_item *array;
int max = 10;

/* initializing hash table array */
void init_array()
{
    int i;
    for (i = 0; i < max; i++)
    {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}
/* to every key, it will generate a corresponding index */
int hashcode(int key)
{
    return (key % max);
}
int size = 0;
// size dari hashtable
int size_of_hashtable()
{
    return size;
}
void insert(int key, int value)
{
    int index = hashcode(key);
    int i = index;

    /* creating new item to insert in the hash table array */
    struct item *new_item = (struct item *)
        malloc(sizeof(struct item));
    new_item->key = key;
    new_item->value = value;
    new_item->next = NULL;

    if (array[i].data == NULL)
    {
        array[i].data = new_item;
        array[i].flag = 1;
    }
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct item *temp = array[i].data;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_item;
    }

    size++;
    printf("\n Key (%d) has been inserted \n ", key);
}
void remove_element(int key)
{
    int index = hashcode(key);
    int i = index;

    /* probing through array until we reach an empty space
where not even once an element had been present */
    while (array[i].flag != 0)
    {
        if (array[i].flag == 1 && array[i].data->key == key)
        {
            // case when data key matches the given key
            array[i].flag = 2;
            array[i].data = NULL;
            size--;
            printf("\n Key(% d) has been removed \n ", key);
            return;
        }
        i = (i + 1) % max;
        if (i == index)
        {
            break;
        }
    }
    printf("\n This key does not exist \n ");
}
/* to display all the elements of hash table */
void display()
{
    int i;

    for (i = 0; i < max; i++)
    {
        struct item *current = (struct item *)array[i].data;
        if (current == NULL)
        {
            printf("\nArray[%d] has no elements \n", i);
        }
        else
        {
            struct item *temp = array[i].data;
            printf("\nArray[%d] has elements - : \n ", i);
            while (current)
            {
                printf("     %d(key) and %d(value)\n", current->key, current->value);
                current = current->next;
            }
        }
    }
}

int main()
{
    int choice, key, value, n, c;
    array = (struct hashtable_item *)malloc(max * sizeof(struct hashtable_item));
    init_array();

    do
    {
        system("cls");
        printf(" Implementation of Hash Table in C with Linear Probing \n\n ");

        printf("MENU-: \n1.Inserting item in the Hash Table"
               "\n2.Removing item from the Hash Table"
               "\n3.Check the size of Hash Table"
               "\n4.Display Hash Table"
               "\n\n Please enter your choice-:");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            system("cls");
            printf("Inserting element in Hash Table\n");
            printf("Enter key :\t");
            scanf("%d", &key);
            printf("Enter value :\t");
            scanf("%d", &value);
            insert(key, value);
            break;

        case 2:
            system("cls");
            printf("Deleting in Hash Table \n Enter the key to delete-:");
            scanf("%d", &key);
            remove_element(key);
            break;

        case 3:
            system("cls");
            n = size_of_hashtable();
            printf("Size of Hash Table is-:%d\n", n);
            break;

        case 4:
            system("cls");
            display();
            break;

        default:

            printf("Wrong Input\n");
        }

        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);

    } while (c == 1);

    getch();
}