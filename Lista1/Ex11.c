#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    long *pres, comp;
    int pres_count, ver = 0, result = 0;
    scanf("%d", &pres_count);

    pres = (long *)malloc(sizeof(long) * pres_count);

    for (size_t i = 0; i < pres_count; i++)
    {
        scanf("%li", &pres[i]);
    }

    for (size_t i = 0; i < pres_count; i++)
    {
        comp = pres[i];

        for (size_t j = i + 1; j < pres_count; j++)
        {
            if (comp == pres[j])
            {
                ver = 1;
            }
        }

        if (ver == 0)
        {
            result++;
        }
        else
        {
            ver = 0;
        }
    }

    printf("%d", result);

    return 0;
}
