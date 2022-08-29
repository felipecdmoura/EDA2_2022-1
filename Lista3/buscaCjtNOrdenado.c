#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Num
{
    long num;
    long index;
} Num;

void merge(Num *vet, long l, long mid, long r)
{
    long count_1, count_2, temp_count;
    Num *temp;

    count_1 = l;
    count_2 = mid + 1;
    temp_count = 0;

    temp = (Num *)malloc(sizeof(Num) * (r - l + 1));

    while (count_1 <= mid && count_2 <= r)
    {
        if (vet[count_1].num <= vet[count_2].num)
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

void mergeSort(Num *vet, long l, long r)
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

void search(long num, Num *vet, int l, int r)
{

    long mid = (r + l) / 2;

    if (num == vet[mid].num)
    {
        printf("%li\n", vet[mid].index);
        return;
    }

    if (l >= r)
    {
        printf("-1\n");
        return;
    }

    if (num > vet[mid].num)
    {
        search(num, vet, (mid + 1), r);
    }
    else if (num < vet[mid].num)
    {
        search(num, vet, l, (mid - 1));
    }
}

int main()
{
    long M, N, rslt;
    Num *Mvet, *Nvet;
    bool ver = false;

    scanf("%li %li", &N, &M);

    Mvet = (Num *)malloc(sizeof(Num) * M + 1);
    Nvet = (Num *)malloc(sizeof(Num) * N + 1);

    for (size_t i = 0; i < N; i++)
    {
        scanf("%li", &Nvet[i].num);
        Nvet[i].index = i;
    }

    for (size_t i = 0; i < M; i++)
    {
        scanf("%li", &Mvet[i].num);
        Mvet[i].index = i;
    }

    mergeSort(Nvet, 0, (N - 1));

    for (size_t i = 0; i < M; i++)
    {
        search(Mvet[i].num, Nvet, 0, (N - 1));
    }

    free(Mvet);
    free(Nvet);
    return 0;
}