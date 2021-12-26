#include <stdio.h>
#include <stdlib.h>

struct item
{
    int key;
    int value;
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
int max = 11;

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
    int q = 1;

    /* creating new item to insert in the hash table array */
    struct item *new_item = (struct item *)
        malloc(sizeof(struct item));
    new_item->key = key;
    new_item->value = value;

    /* probing through the array until we reach an empty space - LINEAR PROBING*/
    while (array[i].flag == 1)
    {
        if (array[i].data->key == key)
        {
            /* case where already existing key matches the given key */
            printf("\n Key already exists, hence updating its value \n ");
            array[i].data->value = value;
            return;
        }
        i = index;
        i = (i + q * q) % max; //maju satu langkah
        q++;
        if (i == index)
        //jika sudah mengecek satu - satu index sampai balik lagi ke index penuh
        {
            printf("\n Hash table is full, cannot insert any more item \n ");
            return;
        }
    }

    array[i].flag = 1;
    array[i].data = new_item;
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
            printf("\n Array[%d] has no elements \n ", i);
        }
        else
        {
            printf("\n Array[%d] has elements - : \n %d(key) and %d(value) ", i, current->key, current->value);
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