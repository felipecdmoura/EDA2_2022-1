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
    long n_inp, vet_size = 1, vet_count = 0;

    long vet[1000000];

    for (size_t i = 0; i < 8; i++)
    {
        scanf("%li", &n_inp);
        // vet_size += n_inp;
        //  long *vet = realloc(vet, sizeof(long) * vet_size);

        for (size_t j = 0; j < n_inp; j++)
        {
            scanf("%li", &vet[vet_count++]);
        }
    }

    mergeSort(vet, 0, (vet_count - 1));

    for (size_t i = 0; i < vet_count; i++)
    {
        printf("%li ", vet[i]);
    }

    return 0;
}