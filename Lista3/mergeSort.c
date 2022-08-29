#include <stdio.h>
#include <stdlib.h>

void merge(int *vet, int l, int mid, int r)
{
    int count_1, count_2, temp_count;
    int *temp;

    count_1 = l;
    count_2 = mid + 1;
    temp_count = 0;

    temp = (int *)malloc(sizeof(int) * (r - l + 1));

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

void mergeSort(int *vet, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (r + l) / 2;

    mergeSort(vet, l, mid);
    mergeSort(vet, mid + 1, r);
    merge(vet, l, mid, r);
}

int main()
{
    int *vet, n_nums;

    scanf("%d", &n_nums);
    vet = (int *)malloc(sizeof(int) * n_nums);

    for (size_t i = 0; i < n_nums; i++)
    {
        scanf("%d", &vet[i]);
    }

    mergeSort(vet, 0, (n_nums - 1));

    for (size_t i = 0; i < n_nums; i++)
    {
        printf("%d ", vet[i]);
    }

    return 0;
}