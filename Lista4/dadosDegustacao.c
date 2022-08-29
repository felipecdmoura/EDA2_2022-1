#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{

    int seq_size;
    char seq_char;
    int seq_pos;
} Data;

#define Key(A) (A.seq_size)
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
        if (vet[count_1].seq_size < vet[count_2].seq_size)
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

int main()
{
    char str[100002];
    int str_count = 0, data_count = 0;

    Data *data;
    scanf("%c", &str[str_count]);

    while (str[str_count] != '\n')
    {
        str_count++;
        scanf("%c", &str[str_count]);
    }

    data = (Data *)malloc(sizeof(Data) * (str_count + 1));

    data[data_count].seq_char = str[0];
    data[data_count].seq_pos = 0;
    data[data_count].seq_size = 1;
    for (size_t i = 1; i < str_count; i++)
    {

        if (str[i] != str[i - 1] && str[i] != '\n')
        {
            data_count++;
            data[data_count].seq_size = 1;
            data[data_count].seq_char = str[i];
            data[data_count].seq_pos = i;
        }
        else
        {
            data[data_count].seq_size++;
        }
    }
    data_count++;
    mergeSort(data, 0, data_count - 1);

    for (int i = data_count - 1; i >= 0; i--)
    {
        printf("%d %c %d\n", data[i].seq_size, data[i].seq_char, data[i].seq_pos);
    }

    return 0;
}