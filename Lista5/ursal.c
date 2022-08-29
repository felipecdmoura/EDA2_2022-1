#include <stdio.h>
#include <stdlib.h>

#define Key(A) (A)
#define hash(v, M) (v % M)

static long M, N;
static int *ht;

void initHash(long max)
{

    M = max;
    N = 0;

    ht = calloc(M, sizeof(int));
}

int mostFrequent(long inp)
{
    int i = hash(inp, M);

    ht[i]++;
    return ht[i];
}

int main()
{

    long S, F, E, vote, temp;
    long pres = 0, pres_count = 0, sen = 0, sen_count = 0, depFed = 0, depFed_count = 0, depEst = 0, depEst_count = 0;
    int valid_qtd = 0, invalid_qtd = 0;

    initHash(100001);

    scanf("%li %li %li", &S, &F, &E);

    while (scanf("%li", &vote) != EOF)
    {
        if (vote > 0)
        {
            valid_qtd++;

            // presidente
            if (vote >= 0 && vote < 100)
            {
                temp = mostFrequent(vote);

                if (temp > pres_count)
                {
                    pres_count = temp;
                    pres = vote;
                }
            }

            // senadores
            if (vote >= 100 && vote < 1000)
            {
                temp = mostFrequent(vote);

                if (temp > sen_count)
                {
                    sen_count = temp;
                    sen = vote;
                }
            }

            // dep federal
            if (vote >= 1000 && vote < 10000)
            {
                temp = mostFrequent(vote);

                if (temp > depFed_count)
                {
                    depFed_count = temp;
                    depFed = vote;
                }
            }

            // dep estadual
            if (vote >= 10000 && vote < 100000)
            {
                temp = mostFrequent(vote);

                if (temp > depEst_count)
                {
                    depEst_count = temp;
                    depEst = vote;
                }
            }
        }
        else
        {
            invalid_qtd++;
        }
    }

    printf("%d %d\n", valid_qtd, invalid_qtd);
    printf("%li\n", pres);
    printf("%li\n", sen);
    printf("%li\n", depFed);
    printf("%li\n", depEst);

    free(ht);
    return 0;
}