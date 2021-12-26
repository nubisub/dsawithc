#include<stdio.h>
#include<string.h>

#define N 50

char STACK[N], TOP; //menggunakan 1 stack

void push(char stack[],char item)
{
    if(TOP == N-1){
        printf("\nSTACK penuh, tidak dapat ditambahkan item baru\n");
    }
    else{
        TOP++;
        stack[TOP]=item;
    }
}

char pop(char stack[])
{
    char itemPop;
    if(TOP == -1){
        printf("STACK sudah kosong.\n");
        exit(1);
    }
    else{
        itemPop = stack[TOP];
        TOP--;
    }

    return itemPop;
}

int isMatch(char a,char b)
{
    if(a=='[' && b==']')
        return 1;
    else if(a=='{' && b=='}')
        return 1;
    else if(a=='(' && b==')')
        return 1;
    else
        return 0;
}

int isBalanced(char input[])
{
    for(int i=0; i<strlen(input) ;i++)
    {
        if(input[i]=='(' || input[i]=='{' || input[i]=='[')
        {
            push(STACK, input[i]);
        }
        else if(input[i]==')' || input[i]=='}' || input[i]==']')
        {
            if(!isMatch(pop(STACK), input[i]))
            {
int isBalanced(char input[])
{
    for(int i=0; i<strlen(input) ;i++)
    {
        if(input[i]=='(' || input[i]=='{' || input[i]=='[')
        {
            push(STACK, input[i]);
        }
        else if(input[i]==')' || input[i]=='}' || input[i]==']')
        {
            if(!isMatch(pop(STACK), input[i]))
            {
                return 0;
            }
        }
    }

    if(TOP == -1) //STACK kosong
        return 1;
    else
        return 0; //jumlah tidak seimbang
}

int main()
{
    TOP = -1;
    char input[N];
    
    printf("Input kombinasi kurung: ");
    scanf("%s",&input);

    if(isBalanced(input)){
        printf("Input seimbang!");
    } else {
        printf("Input tidak seimbang!");
    }


    return 0;
}
