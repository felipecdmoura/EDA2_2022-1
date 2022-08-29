#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int sim_num, total, eof;
    char answer[3];
    eof = 1;
    total = 0;

    while (eof != EOF)
    {
        sim_num = 0;

        for (size_t i = 0; i <= 9; i++)
        {
            eof = scanf("%s", answer);

            if (eof == EOF)
            {
                break;
            }

            if (strcmp(answer, "sim") == 0)
            {
                sim_num++;
            }
        }

        // printf("<<Change>>");
        if (sim_num >= 2)
        {
            total++;
        }
    }

    printf("%d", total);

    return 0;
}
