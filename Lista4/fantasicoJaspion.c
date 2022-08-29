
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
    char ptbr[81];
    char jpn[81];
} Data;

Data data[1000000];

#define Key(A) (A.jpn)
#define less(A, B) (strcmp(Key(A), Key(B)) < 0)
#define exch(A, B)  \
    {               \
        Data T = A; \
        A = B;      \
        B = T;      \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(B, A)) \
            exch(A, B); \
    }

int separa(Data *data, int l, int r)
{
    int count = l;
    Data p = data[r];

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

void quickSort(Data *data, int l, int r)
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

int search(char *str, Data *vet, int l, int r)
{

    int mid = (r + l) / 2;
    // int rtn = mid;

    if (strcmp(str, vet[mid].jpn) == 0)
    {
        return mid;
    }

    if (l >= r)
    {

        return -1;
    }

    if (strcmp(str, vet[mid].jpn) > 0)
    {
        mid = search(str, vet, (mid + 1), r);
    }
    else if (strcmp(str, vet[mid].jpn) < 0)
    {
        mid = search(str, vet, l, (mid - 1));
    }
    return mid;
}

void traduz()
{
    int M, N;
    scanf("%d %d", &M, &N);

    for (size_t i = 0; i < M; i++)
    {
        scanf(" %[^\n]", data[i].jpn);
        scanf(" %[^\n]", data[i].ptbr);
    }

    quickSort(data, 0, M - 1);

    for (size_t i = 0; i < N; i++)
    {
        char str[81], p;

        while (scanf(" %s%c", str, &p) == 2)
        {
            int pos = search(str, data, 0, M - 1);

            if (pos < 0)
            {
                printf("%s", str);
            }
            else
            {
                printf("%s", data[pos].ptbr);
            }

            printf("%c", p);

            if (p == '\n')
            {
                break;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    for (size_t i = 0; i < T; i++)
    {
        traduz();
        printf("\n");
    }

    return 0;
}