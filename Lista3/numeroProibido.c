#include <stdio.h>
#include <stdlib.h>

void merge(long *vet, long l, long mid, long r)
{
    long count_1, count_2, temp_count;
    long *temp;

    count_1 = l;
    count_2 = mid + 1;
    temp_count = 0;

    temp = (long *)malloc(sizeof(long) * (r - l + 1));

    while (count_1 <= mid && count_2 <= r)
    {
        if (vet[count_1] <= vet[count_2])
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

void mergeSort(long *vet, long l, long r)
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

void search(long num, long *vet, int l, int r)
{

    long mid = (r + l) / 2;

    if (num == vet[mid])
    {
        printf("sim\n");
        return;
    }

    if (l >= r)
    {
        printf("nao\n");
        return;
    }

    if (num > vet[mid])
    {
        search(num, vet, (mid + 1), r);
    }
    else if (num < vet[mid])
    {
        search(num, vet, l, (mid - 1));
    }
}

int main()
{
    int N;
    long inp, *Pi;

    scanf("%d", &N);

    Pi = (long *)malloc(sizeof(long) * N);

    for (size_t i = 0; i < N; i++)
    {
        scanf("%li", &Pi[i]);
    }

    mergeSort(Pi, 0, (N - 1));

    while (scanf("%li", &inp) != EOF)
    {
        search(inp, Pi, 0, (N - 1));
    }

    return 0;
}