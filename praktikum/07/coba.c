#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define MAX 6
int intArray[MAX];

int itemcount = 0;
int peek()
{
    return intArray[0];
}

bool isempty()
{
    return itemcount == 0;
}
bool isfull()
{
    return itemcount == MAX;
}
int size()
{
    return itemcount;
}

void insert(int data)
{
    int i = 0;
    if (!isfull())
    {
        if (itemcount == 0)
        {
            intArray[itemcount] = data;
        }
        else
        {
            for (i = itemcount - 1; i >= 0; i--)
            {
                if (data > intArray[i])
                {
                    intArray[i + 1] = intArray[i];
                }
                else
                {
                    break;
                }
            }
            intArray[i + 1] = data;
        }
        itemcount++;
    }
}
void removedata()
{
    for (int i = 0; i < itemcount; i++)
    {
        intArray[i] = intArray[i + 1];
    }
    itemcount--;
}

void display()
{
    for (int i = 0; i < itemcount; i++)
    {
        printf("%d, ", intArray[i]);
    }
}

int main()
{

    insert(3);
    insert(5);
    insert(9);
    insert(1);
    insert(12);

    printf("Queue = ");
    display();
    printf("\nElement at front = %d\n", peek());

    removedata();
    printf("\n---Setelah Remove---\n");

    printf("Queue = ");
    display();
    printf("\nElement at front = %d\n", peek());
}