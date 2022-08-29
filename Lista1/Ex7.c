#include <stdio.h>

int count7(char num[100], int count_7, int loop_count, int digits_num)
{
    if (loop_count == digits_num)
    {
        return count_7;
    }

    if (num[loop_count] == '7')
    {
        count_7++;
    }

    loop_count++;
    count_7 = count7(num, count_7, loop_count, digits_num);
    return count_7;
}

int main(int argc, char const *argv[])
{
    unsigned long num;
    int loop_count = 0;
    int digits_num = 0;
    int count_7 = 0;
    char num_string[100];

    scanf("%lu", &num);
    digits_num = (num == 0) ? 1 : log10(num) + 1;

    sprintf(num_string, "%lu", num);

    count_7 = count7(num_string, count_7, loop_count, digits_num);
    printf("%d", count_7);
    return 0;
}
