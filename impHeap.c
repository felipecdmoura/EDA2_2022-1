#include <stdio.h>
#include <stdlib.h>

#define exc(A, B)  \
    {              \
        int T = A; \
        A = B;     \
        B = T;     \
    }

typedef struct heap
{
    int *num;
    int count;
} heap;

void fixUp(int *num, int k)
{
    while (k > 1 && num[k / 2] < num[k])
    {
        exc(num[k], num[k / 2]);
        k = k / 2;
    }
}

void fixDown(int *num, int k, int heap_size)
{
    int j;
    while (2 * k <= heap_size)
    {
        j = 2 * k;

        if (j < heap_size && num[j] < num[j + 1])
        {
            j++;
        }

        if (num[k] > num[j])
        {
            break;
        }

        exc(num[k], num[j]);

        k = j;
    }
}
void heap_init(heap *hp, int heap_size)
{
    hp->num = malloc(sizeof(int) * (heap_size + 1));
    hp->count = 0;
}

void heap_insert(heap *hp, int new)
{

    hp->num[++hp->count] = new;
    fixUp(hp->num, hp->count);
}

int del_max(heap *hp)
{

    int rtn;

    rtn = hp->num[1];

    exc(hp->num[1], hp->num[hp->count]);
    fixDown(hp->num, 1, --hp->count);

    return rtn;
}

int main()
{
    int a;
    heap *hp;
    int count = 0;
    heap_init(hp, 20);

    while (scanf("%d", &a) != EOF)
    {
        count++;
        heap_insert(hp, a);
    }

    printf(">>");

    for (size_t i = 1; i <= count; i++)
    {
        printf("%d ", del_max(hp));
    }
    printf("\n");
    return 0;
}