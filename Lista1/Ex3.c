#include <stdio.h>

int main(int argc, char const *argv[])
{

    int count, num, sum;

    sum = 0;

    scanf("%d", &count);

    for (size_t i = 0; i < count; i++)
    {
        scanf("%d", &num);

        sum = sum + num;
    }

    printf("%d", sum);

    return 0;
}
