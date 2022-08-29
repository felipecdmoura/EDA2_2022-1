#include <stdio.h>

void insertionSort(int vet[50000], int l, int r)
{
    int temp, count;

    for (size_t i = (l + 1); i <= r; i++)
    {
        count = i;
        temp = vet[i];

        while (temp < vet[count - 1] && (count - 1) >= l)
        {
            vet[count] = vet[count - 1];
            count--;
        }
        vet[count] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int eof;
    int nums[50000];
    int count = 0;

    while (eof = scanf("%d", &nums[count++]) != EOF)
    {
    }

    insertionSort(nums, 0, (count - 2));

    for (size_t i = 0; i <= (count - 2); i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
