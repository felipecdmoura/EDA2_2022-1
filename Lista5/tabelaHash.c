#include <stdio.h>
#include <stdlib.h>

#define Key(A) (A)
#define hash(v, M) ((618033 * (unsigned)v) % M)
#define hashtwo(v, M) (v % 97 + 1)
#define eq(A, B) (Key(A) == Key(B))
#define nullitem -1
#define null(A) (eq(ht[A], nullitem))

int M, N;
int *ht;

void initHash(int max)
{

    M = max;
    N = 0;

    ht = malloc(sizeof(int) * M);

    for (size_t i = 0; i < M; i++)
    {
        ht[i] = nullitem;
    }
}

void insertHash(int inst)
{
    int i = hash(Key(inst), M);
    int k = hashtwo(Key(inst), M);

    while (!null(i))
    {
        i = (i + k) % M;
    }

    ht[i] = inst;
    N++;
}

int searchHash(int v)
{

    int i = hash(v, M);
    int k = hashtwo(v, M);

    while (!null(i))
    {
        if (eq(v, Key(ht[i])))
        {
            return ht[i];
        }
        else
        {
            i = (i + k) % M;
        }
    }

    return nullitem;
}