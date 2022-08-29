#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int str_num, sum, *result;
    char str[101];

    scanf("%d", &str_num);

    result = (int *)malloc(sizeof(int) * str_num);

    for (size_t i = 0; i < str_num; i++)
    {
        sum = 0;
        scanf(" %[^\n]", str);

        for (size_t i = 0; i < sizeof(str); i++)
        {
            if (str[i] == '\0')
            {
                break;
            }

            if (str[i] >= '0' && str[i] <= '9')
            {
                sum += (str[i] - '0');
            }
        }

        result[i] = sum;
    }

    for (size_t i = 0; i < str_num; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}
