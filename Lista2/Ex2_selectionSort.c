#include <stdio.h>

void selectionSort(int vet[1000], int l, int r)
{
    for (size_t i = l; i <= r; i++)
    {
        int temp = vet[i];
        int pos = i;
        for (size_t k = (i + 1); k <= r; k++)
        {
            if (vet[k] < temp)
            {
                temp = vet[k];
                pos = k;
            }
        }

        vet[pos] = vet[i];
        vet[i] = temp;
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

    selectionSort(nums, 0, (count - 2));

    for (size_t i = 0; i <= (count - 2); i++)
    {
        printf("%d", nums[i]);
    }

    return 0;
}
