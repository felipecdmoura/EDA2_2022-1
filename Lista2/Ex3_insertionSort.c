#include <stdio.h>

void insertionSort(int vet[1000], int l, int r)
{
    for (size_t i = l + 1; i <= r; i++)
    {
        for (size_t k = i; k > l; k--)
        {
            if (vet[k] < vet[k - 1])
            {
                int temp = vet[k];
                vet[k] = vet[k - 1];
                vet[k - 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int eof;
    int nums[1000];
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
