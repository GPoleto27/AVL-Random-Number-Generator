#include "Random.h"
#include "AVL.h"
#include "time.h"

int main()
{
    FILE *fp = fopen("PCD.txt", "a+");
    register int i;
    int *num = malloc(MAX_NUM * sizeof(int)), Min;
    long long unsigned int rand_num, Max;
    srand(time(NULL));
    noh *arvore = NULL;
    printf ("Numero de itens: %d\n", MAX_NUM);
    GET_FREQ;
    SET_FREQ;
    BEGIN;
    for (i = 0; i < MAX_NUM; i++)
    {
        rand_num = 0;
        geraAleatorio(&rand_num);
        if (!temRepeticao(arvore, rand_num))
        {
            arvore = insert(arvore, rand_num);
            num [i] = rand_num;
        }
        else i--;
    }
    CLOSE;
    printf ("Tempo de geracao e atribuicao: ");
    SHOWTIME;
    BEGIN;
    fprintfERD(fp, arvore);
    CLOSE;
    printf ("Tempo de impressao em arquivo: ");
    SHOWTIME;
    BEGIN;
    MaxMin1(num, &Max, &Min);
    CLOSE;
    printf ("Tempo MaxMin1:");
    SHOWTIME;

    BEGIN;
    MaxMin2(num, &Max, &Min);
    CLOSE;
    printf ("Tempo MaxMin2:");
    SHOWTIME;

    BEGIN;
    MaxMin3(num, &Max, &Min);
    CLOSE;
    printf ("Tempo MaxMin3:");
    SHOWTIME;

    fclose (fp);
    return 0;
}
