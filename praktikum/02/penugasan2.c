/* Aturan Scope pada Bahasa C */
#include <stdio.h>

int main()
{
    {
        int x = 10, y = 20; //Global
        {
            printf("x = %d, y = %d\n", x, y);
            {
                int y = 40; //local
                x++;
                y++;
                printf("x = %d, y = %d\n", x, y);
            }
            printf("x = %d, y = %d\n", x, y);
        }
    }
    system("pause");
    return 0;
}
