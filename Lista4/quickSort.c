
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
    int num
} Data;

#define Key(A) (A.num)
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B)  \
    {               \
        Data T = A; \
        A = B;      \
        B = T;      \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(B, A)) \
            exch(A, B); \
    }

int separa(Data *data, int l, int r)
{
    int count = l;
    Data p = data[r];

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

void quickSort(Data *data, int l, int r)
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

int main()
{

    int size;
    Data *nums;

    scanf("%d", &size);
    nums = (Data *)malloc(sizeof(Data) * size);

    for (size_t i = 0; i < size; i++)
    {
        scanf("%d", &nums[i].num);
    }

    quickSort(nums, 0, size - 1);

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", nums[i].num);
    }

    return 0;
}