#include <stdio.h>
void main()
{
    int umur, tinggi, paling, tiup ;
    printf(" Birthday Cake\n");
    printf("===============\n");
    printf("Umur = ");
    scanf("%d", &umur);

    for (int i = 1; i <= umur; i++)
    {
        printf("Tinggi Lilin %d = ", i);
        scanf("%d", &tinggi);
        if (paling < tinggi)
        {
            paling = tinggi;
            tiup = 1;
        }
        else if (paling == tinggi)
        {
            tiup = tiup + 1;
        }
    }
    printf("Jumlah Lilin Yang dapat ditiup = %d\n", tiup);
    system("pause");
}