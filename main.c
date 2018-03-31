#include "AVL.h"
#define MAX_NUM 1000000

void geraAleatorio(long long unsigned int *num)
{
    register int i;
    for (i = 0; i < 1 +(rand() % 15); i++)
    {
        *num *= 10;
        *num += rand()%10;
    }
}

int main()
{
    FILE *fp = fopen("PCD.txt", "a+");
    register int i;
    long long unsigned int rand_num;
    srand(time(NULL));
    noh *arvore = NULL;
    printf ("Numero de itens: %d\n", MAX_NUM);
    for (i = 0; i < MAX_NUM; i++)
    {
        rand_num = 0;
        geraAleatorio(&rand_num);
        if (!temRepeticao(arvore, rand_num))
            arvore = insert(arvore, rand_num);
        else
            i--;
    }

    fprintfERD(fp, arvore);
    fclose (fp);

    return 0;
}
