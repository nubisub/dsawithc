// include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// boolean function
int strmatch(char str[], char pattern[], int n, int m)
{
    // wildcard search
    int i, j;
    // for (i = 0; i <= n; i++)
    // {
    //     for (j = 0; j < m; j++)
    //     {
    //         if (pattern[j] == '?')
    //         {
    //             // match
    //             // printf("jancok");
    //             continue;
    //         }
    //         if (pattern[j] != str[i + j])
    //             break;
    //     }
    //     if (j == m)
    //         return 1;
    // }
    // return 0;

    for (i = 0, j = 0; i < n && j < m; i++)
    {
        if (pattern[j] == '*')
        {
            j++;
            i--;
        }
        else if (pattern[j] == '?' || str[i] == pattern[j])
        {
            j++;
        }
        else
        {
            break;
        }
    }
    if (j == m)
    {
        return 1;
    }
    return 0;
}
// main
int main(void)
{
    // declare boolean

    char str[] = "computer";
    char pattern[] = "c*m";
    int n = strlen(str);
    int m = strlen(pattern);
    // prin a
    // printf("%d", a);
    // print n
    // printf("%d", n);

    if (strmatch(str, pattern, n, m))
        printf("matches \n");
    else
        printf("does not match \n");
    return 0;
}