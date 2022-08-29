#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
long temp[140000];

int removeDuplicate(long *vet, long l, long N)
{
    long size = N;
    int count = 0;
    bool ver = false;
    long *temp;
    temp = (long *)malloc(sizeof(long) * N);
    for (size_t i = l; i < N; i++)
    {

        if (vet[i] == vet[i + 1])
        {
            ver = true;
            size--;
        }

        if (ver == false)
        {
            temp[count++] = vet[i];
        }
        ver = false;
    }

    count = 0;

    for (size_t i = l; i < N; i++)
    {
        vet[i] = temp[count++];
    }

    free(temp);
    return size;
}

int merge(long *vet, long l, long mid, long r)
{
    int count_1, count_2, temp_count;

    count_1 = l;
    count_2 = mid + 1;
    temp_count = 0;

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

    return r;
}

int mergeSort(long *vet, long l, long r)
{
    if (l >= r)
    {
        return r;
    }
    long mid = (r + l) / 2;

    mergeSort(vet, l, mid);
    mergeSort(vet, mid + 1, r);
    r = merge(vet, l, mid, r);

    return r;
}

int makeSums(long *vet, long l, long N)
{
    int count = 0;
    long sums[70000], sums_size = (N / 2);

    for (int i = l; i <= N - 1; i += 2)
    {

        sums[count] = vet[i] + vet[i + 1];
        vet[count + N] = sums[count];
        count++;
    }

    return N + sums_size;
}

int main()
{
    long N;
    long vet[140000];

    scanf("%li", &N);

    for (size_t i = 0; i < N; i++)
    {
        scanf("%li", &vet[i]);
    }

    N = mergeSort(vet, 0, (N - 1)) + 1;
    N = removeDuplicate(vet, 0, N);

    if (N % 2 != 0)
    {

        vet[N] = 1000000000;
        N++;
    }

    N = makeSums(vet, 0, N);
    N = mergeSort(vet, 0, N - 1) + 1;
    N = removeDuplicate(vet, 0, N);

    for (size_t i = 0; i < N; i += 4)
    {
        printf("%li\n", vet[i]);
    }
    printf("Elementos: %li\n", N);

    return 0;
}