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

    int N, max, max_count, temp;
    long inp;

    while (1)
    {
        max_count = 0;
        max = 0;
        scanf("%d", &N);

        if (N == 0)
        {
            break;
        }

        initHash(1000000);

        for (size_t i = 0; i < N; i++)
        {
            scanf("%li", &inp);
            temp = mostFrequent(inp);

            if (temp > max_count)
            {
                max_count = temp;
                max = inp;
            }
        }

        printf("%d\n", max);

        free(ht);
    }

    return 0;
}