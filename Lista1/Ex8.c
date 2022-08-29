#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    int *nums, *rslt;
    int inpt, sum_lim;
    int sum = 0;
    int num_count = 0, rslt_count = 0;

    nums = (int *)malloc(sizeof(int));
    rslt = (int *)malloc(sizeof(int));

    while (inpt != 0)
    {
        scanf("%d", &inpt);
        if (inpt == 0)
        {
            break;
        }

        num_count++;
        nums = (int *)realloc(nums, (sizeof(int) * num_count));
        nums[num_count - 1] = inpt;
    }

    scanf("%d", &sum_lim);

    for (size_t i = 0; i < num_count; i++)
    {
        sum += nums[i];
        if (sum > sum_lim)
        {
            rslt_count++;
            rslt = (int *)realloc(rslt, (sizeof(int) * rslt_count));
            rslt[rslt_count - 1] = nums[i];
            sum = 0;
        }
    }

    for (int i = (rslt_count - 1); i >= 0; i--)
    {
        printf("%d\n", rslt[i]);
    }

    return 0;
}
