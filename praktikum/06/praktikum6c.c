#include <stdio.h>
typedef struct
{
    int item[50];
    int count;
} stack;

void initializestack(stack *s)
{
    s->count = 0;
}

int empty(stack *s)
{
    return (s->count == 0);
}

int full(stack *s)
{
    return (s->count == 49);
}

void push(int x, stack *s)
{
    if (full(s))
        printf(" Bilangan terlalu besar !\n ");
    else
    {
        s->item[s->count] = x;
        ++(s->count);
    }
}

int pop(stack *s)
{
    if (empty(s))
        return (0);
    else
    {
        --(s->count);
        return (s->item[s->count]);
    }
}

int prepush(int n, stack *s)
{
    int l;
    l = n % 8;
    push(l, s);
    if (n >= 8)
    {
        prepush(n / 8, s);
    }
}

int show(int input, int i, stack *s)
{
    if (input == 0)
    {
        printf("0");
    }
    else if (i > 0)
    {
        printf("%d", pop(s));
        show(input, i - 1, s);
    }
}

void main()
{
    int i, n, l;
    int input;
    stack tumpukan;
    printf("Program konversi Desimal ke Oktal\n\n");
    initializestack(&tumpukan);
    printf("Masukkan bilangan desimal = ");
    scanf("%d", &input);
    prepush(input, &tumpukan);
    printf("Hasil konversi ke oktal   = ");
    show(input, tumpukan.count, &tumpukan);

    printf("\n");
    system("pause");
}