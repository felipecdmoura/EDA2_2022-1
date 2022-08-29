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

long search(long num, long *vet, int l, int r)
{

    long mid = (r + l) / 2;
    long rtn = mid;

    if (num == vet[mid])
    {
        return rtn;
    }

    if (l >= r)
    {
        if (num > vet[mid])
        {
            return rtn + 1;
        }
        else
        {
            return rtn;
        }

        return rtn;
    }

    if (num > vet[mid])
    {
        rtn = search(num, vet, (mid + 1), r);
    }
    else if (num < vet[mid])
    {
        rtn = search(num, vet, l, (mid - 1));
    }
    return rtn;
}

int main()
{
    long M, N, *Mvet, *Nvet, rslt;

    scanf("%li %li", &N, &M);

    Mvet = (long *)malloc(sizeof(long) * M + 1);
    Nvet = (long *)malloc(sizeof(long) * N + 1);

    for (size_t i = 0; i < N; i++)
    {
        scanf("%li", &Nvet[i]);
    }

    for (size_t i = 0; i < M; i++)
    {
        scanf("%li", &Mvet[i]);
    }

    mergeSort(Nvet, 0, (N - 1));

    for (size_t i = 0; i < M; i++)
    {
        rslt = search(Mvet[i], Nvet, 0, (N - 1));
        printf("%li\n", rslt);
    }

    free(Mvet);
    free(Nvet);
    return 0;
}