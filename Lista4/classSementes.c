
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
    long long code;
    long grade;
} Data;

Data seeds[10000001];

#define Key1(A) (A.grade)
#define Key2(A) (A.code)
#define less1(A, B) (Key1(A) < Key1(B))
#define less2(A, B) (Key2(A) < Key2(B))
#define exch(A, B)  \
    {               \
        Data T = A; \
        A = B;      \
        B = T;      \
    }
#define cmpexch1(A, B)   \
    {                    \
        if (less1(B, A)) \
            exch(A, B);  \
    }

#define cmpexch2(A, B)   \
    {                    \
        if (less2(B, A)) \
            exch(A, B);  \
    }

int separa(Data *data, int l, int r)
{
    int count = l;
    Data p = data[r];

    for (size_t i = l; i < r; i++)
    {
        if (less2(data[i], p))
        {
            exch(data[i], data[count]);
            count++;
        }
    }
    exch(data[count], data[r]);
    return count;
}

void quickselect(Data *data, int l, int r)
{
    int count;
    if (r <= l)
    {
        return;
    }

    cmpexch2(data[(l + r) / 2], data[r]);
    cmpexch2(data[l], data[(l + r) / 2]);
    cmpexch2(data[r], data[(l + r) / 2]);

    count = separa(data, l, r);
    quickselect(data, l, count - 1);
    quickselect(data, count + 1, r);
}

void merge(Data *vet, int l, int mid, int r)
{
    int count_1, count_2, temp_count;
    Data *temp;

    count_1 = l;
    count_2 = mid + 1;
    temp_count = 0;

    temp = (Data *)malloc(sizeof(Data) * (r - l + 1));

    while (count_1 <= mid && count_2 <= r)
    {
        if (vet[count_1].grade <= vet[count_2].grade)
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

void mergeSort(Data *vet, int l, int r)
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

void merge2(Data *vet, int l, int mid, int r)
{
    int count_1, count_2, temp_count;
    Data *temp;

    count_1 = l;
    count_2 = mid + 1;
    temp_count = 0;

    temp = (Data *)malloc(sizeof(Data) * (r - l + 1));

    while (count_1 <= mid && count_2 <= r)
    {
        if (vet[count_1].code <= vet[count_2].code)
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

void mergeSort2(Data *vet, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (r + l) / 2;

    mergeSort2(vet, l, mid);
    mergeSort2(vet, mid + 1, r);
    merge2(vet, l, mid, r);
}

int main()
{
    long k, count = 0, repeats = 0;

    scanf("%li", &k);

    while (scanf("%lli %li", &seeds[count].code, &seeds[count].grade) != EOF)
    {
        count++;
    }

    mergeSort2(seeds, 0, count - 1);
    mergeSort(seeds, 0, count - 1);
    quickselect(seeds, 0, k - 1);
    for (size_t i = 0; i < k; i++)
    {
        printf("%lli %li\n", seeds[i].code, seeds[i].grade);
    }

    return 0;
}