#include <stdio.h>
#include <stdlib.h>

int removeDuplicate(long *vet, long l, long r)
{
    int size = r + 1;

    for (size_t i = l; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (vet[j] == vet[i])
            {
                for (size_t k = j; k < size; k++)
                {
                    vet[k] = vet[k + 1];
                }
                size--;
                j--;
            }
        }
    }
    return size - 1;
}

int merge(long *vet, long l, long mid, long r)
{
    int count_1, count_2, temp_count;
    long *temp;

    count_1 = l;
    count_2 = mid + 1;
    temp_count = 0;

    temp = (long *)malloc(sizeof(long) * (r - l + 2));

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

    r = removeDuplicate(temp, l, r);

    temp_count = 0;

    for (size_t i = l; i <= r; i++)
    {
        vet[i] = temp[temp_count++];
    }

    free(temp);
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

long insert(long num, long *vet, long l, long r)
{

    long mid = (r + l) / 2;
    long rtn = mid;

    if (num == vet[mid])
    {
        return -1;
    }

    if (l >= r)
    {
        return rtn;
    }

    if (num > vet[mid])
    {
        rtn = insert(num, vet, (mid + 1), r);
    }
    else if (num < vet[mid])
    {
        rtn = insert(num, vet, l, (mid - 1));
    }
    return rtn;
}

int makeInsertion(long *vet, long *sums, long l, long r, long N)
{
    long ver;
    for (size_t i = l; i <= r; i++)
    {
        ver = insert(sums[i], vet, 0, N - 1);
        // printf(">%li: {%li} {%d}\n", sums[i], ver, N - 1);
        if (ver != -1 && sums[i] < vet[ver])
        {
            N++;
            for (size_t j = N - 1; j > ver; j--)
            {
                vet[j] = vet[j - 1];
            }
            vet[ver] = sums[i];
        }
        else if (ver != -1 && sums[i] > vet[ver])
        {
            N++;
            if (ver < N - 1)
            {
                for (size_t j = N - 1; j > ver; j--)
                {
                    vet[j] = vet[j - 1];
                }
                vet[ver + 1] = sums[i];
            }
            else
            {
                vet[ver + 1] = sums[i];
            }
        }
    }
    return N;
}

void makeSums(long *vet, long *sums, long l, long r)
{
    int count = 0;
    for (int i = l; i <= r; i += 2)
    {

        sums[count] = vet[i] + vet[i + 1];
        count++;
    }
}

int main()
{
    long N, sums_size;
    long vet[140000], sums[70000];

    scanf("%li", &N);

    // vet = (long *)malloc(sizeof(long) * (N + 1));

    for (size_t i = 0; i < N; i++)
    {
        scanf("%li", &vet[i]);
    }

    N = mergeSort(vet, 0, (N - 1)) + 1;

    if (N % 2 != 0)
    {
        vet[N] = 1000000000;
        N++;
    }

    sums_size = (N / 2);
    // sums = (long *)malloc(sizeof(long) * (sums_size + 1));

    makeSums(vet, sums, 0, N - 1);

    N = makeInsertion(vet, sums, 0, sums_size - 1, N);

    for (size_t i = 0; i < N; i += 4)
    {
        printf("%li\n", vet[i]);
    }
    /* for (size_t i = 0; i < sums_size; i++)
    {
        printf(">>%li\n", sums[i]);
    } */
    printf("Elementos: %li\n", N);

    return 0;
}