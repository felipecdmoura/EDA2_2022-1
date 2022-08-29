
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B)  \
    {               \
        long T = A; \
        A = B;      \
        B = T;      \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(B, A)) \
            exch(A, B); \
    }

int separa(long *data, int l, int r)
{
    int count = l;
    long p = data[r];

    for (size_t i = l; i < r; i++)
    {
        if (less(data[i], p))
        {
            exch(data[i], data[count]);
            count++;
        }
    }
    exch(data[count], data[r]);
    return count;
}

void quickSelect(long *data, int l, int r, int k)
{
    int count;
    if (r <= l)
    {
        return;
    }

    count = separa(data, l, r);
    if (count > k)
        quickSelect(data, l, count - 1, k);
    if (count < k)
        quickSelect(data, count + 1, r, k);
}

void quickSort(long *data, int l, int r)
{
    int count;
    if (r <= l)
    {
        return;
    }

    cmpexch(data[(l + r) / 2], data[r]);
    cmpexch(data[l], data[(l + r) / 2]);
    cmpexch(data[r], data[(l + r) / 2]);

    count = separa(data, l, r);
    quickSort(data, l, count - 1);
    quickSort(data, count + 1, r);
}

int main()
{
    long N, P, ini, end, *id;
    int X;

    scanf("%li %li %d", &N, &P, &X);

    id = (long *)malloc(sizeof(long) * N);

    for (size_t i = 0; i < N; i++)
    {
        scanf("%li", &id[i]);
    }
    ini = X * P;
    end = (ini + X) - 1;
    if (end > N - 1)
    {
        end = N - 1;
    }

    quickSelect(id, 0, N - 1, ini);
    quickSelect(id, ini + 1, N - 1, end);
    quickSort(id, ini, end);

    for (size_t i = ini; i <= end; i++)
    {
        printf("%li\n", id[i]);
    }

    return 0;
}