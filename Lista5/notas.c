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

    int tam, max, max_count, temp;
    int inp;

    max_count = 0;
    max = 0;

    scanf("%d", &tam);

    initHash(101);

    for (size_t i = 0; i < tam; i++)
    {
        scanf("%d", &inp);
        temp = mostFrequent(inp);

        if (temp > max_count)
        {
            max_count = temp;
            max = inp;
        }
        else if (temp == max_count && inp > max)
        {
            max = inp;
        }
    }

    printf("%d\n", max);

    free(ht);

    return 0;
}