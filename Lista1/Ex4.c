#include <stdio.h>

int main(int argc, char const *argv[])
{

    int num, sum, eof;
    eof = 1;
    sum = 0;

    while (eof != EOF)
    {
        eof = scanf("%d", &num);
        sum += 1;
    }

    sum--;
    printf("%d", sum);
    return 0;
}
