#include <stdio.h>

void bubbleSort(int vet[1000], int l, int r)
{
    for (size_t i = l; i < r; i++)
    {
        for (size_t k = l + 1; k <= r; k++)
        {
            if (vet[k] < vet[k - 1])
            {
                int temp = vet[k - 1];
                vet[k - 1] = vet[k];
                vet[k] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int eof;
    int nums[1000];
    int count = 0;

    while (eof = scanf("%d", &nums[count]) != EOF)
    {
        count++;
    }

    bubbleSort(nums, 0, (count - 1));

    for (size_t i = 0; i < count; i++)
    {
        printf("%d", nums[i]);
    }

    return 0;
}
