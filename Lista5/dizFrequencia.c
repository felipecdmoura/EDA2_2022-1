#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Key(A) (A.ch)
#define hash(v, M) (v % M)
#define hashtwo(v, M) (v % 97 + 1)
#define eq(A, B) (Key(A) == Key(B))
#define null(A) (eq(ht[A], nullitem))
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B)  \
    {               \
        Item T = A; \
        A = B;      \
        B = T;      \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(B, A)) \
            exch(A, B); \
    }

typedef struct Item
{
    int ch;
    int count;
} Item;

Item nullitem = {0, 0};

int M, N;
Item *ht;

void merge(Item *vet, long l, long mid, long r)
{
    long count_1, count_2, temp_count;
    Item *temp;

    count_1 = l;
    count_2 = mid + 1;
    temp_count = 0;

    temp = (Item *)malloc(sizeof(Item) * (r - l + 1));

    while (count_1 <= mid && count_2 <= r)
    {
        if (vet[count_1].count <= vet[count_2].count)
        {
            temp[temp_count++] = vet[count_1++];
        }
        else
            temp[temp_count++] = vet[count_2++];
    }

    while (count_1 <= mid)
    {
        temp[temp_count++] = vet[count_1++];
    }
    while (count_2 <= r)
    {
        temp[temp_count++] = vet[count_2++];
    }

    temp_count = 0;
    for (size_t i = l; i <= r; i++)
    {
        vet[i] = temp[temp_count++];
    }

    free(temp);
    return;
}

void mergeSort(Item *vet, long l, long r)
{
    if (l >= r)
    {
        return;
    }
    long mid = (r + l) / 2;

    mergeSort(vet, l, mid);
    mergeSort(vet, mid + 1, r);
    merge(vet, l, mid, r);
}

int separa(Item *data, int l, int r)
{
    int count = l;
    Item p = data[r];

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

void quickSort(Item *data, int l, int r)
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

int hashU(char v, int M)
{
    int h, a = 31415, b = 27183;

    a = a * b % (M - 1);
    h = (a * h + v) % M;

    return h;
}

void initHash(long max)
{

    M = max;
    N = 0;

    ht = malloc(sizeof(Item) * M);

    for (size_t i = 0; i < M; i++)
    {
        ht[i] = nullitem;
    }
}

int mostFrequent(char ch)
{
    int i = ch % M;

    ht[i].ch = ch;
    ht[i].count++;
    return ht[i].count;
}

void printHash(char ch)
{
    int i = hash(ch, M);
}

int main()
{
    char str[1001];
    int count;

    // str = malloc(sizeof(char) * 1001);

    while (scanf("%s", str) != EOF)
    {
        initHash(128);

        count = 0;
        while (str[count] != '\0')
        {
            mostFrequent(str[count]);
            count++;
        }

        quickSort(ht, 0, 127);
        mergeSort(ht, 0, 127);

        count = 127;
        while (ht[count].count != 0)
        {
            count--;
        }
        for (size_t i = count + 1; i <= 127; i++)
        {
            printf("%d %d\n", ht[i].ch, ht[i].count);
        }

        printf("\n");
        free(ht);
    }

    printf("\n");

    return 0;
}