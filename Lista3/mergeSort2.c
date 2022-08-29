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

int main()
{
    long vet[100000], vet_count = 0, n_nums = 0;

    while (scanf("%li", &vet[vet_count++]) != EOF)
    {
        n_nums++;
    }

    mergeSort(vet, 0, (n_nums - 1));

    for (size_t i = 0; i < n_nums; i++)
    {
        printf("%li ", vet[i]);
    }

    return 0;
}