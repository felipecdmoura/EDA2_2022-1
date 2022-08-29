#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Instruction
{
    int code;
    char key[16];
} Instruction;

void insertionSortInstruction(Instruction *inst, int l, int r)
{
    Instruction temp;
    int count;

    for (size_t i = (l + 1); i <= r; i++)
    {
        count = i;
        temp = inst[i];

        while (temp.code < inst[count - 1].code && (count - 1) >= l)
        {
            inst[count] = inst[count - 1];
            count--;
        }
        inst[count] = temp;
    }

    for (size_t i = 0; i < r; i++)
    {
        /* code */
    }
}

int search(int num, Instruction *inst, int l, int r)
{

    while (l <= r)
    {
        int mid = (r + l) / 2;

        if (inst[mid].code == num)
        {
            return mid;
        }
        else if (num < inst[mid].code)
        {
            r = mid - 1;
        }
        else if (num > inst[mid].code)
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int inst_n, nums[60000], mid;
    int nums_count = 0;

    Instruction inst[60000];

    scanf("%d", &inst_n);

    for (size_t i = 0; i < inst_n; i++)
    {
        scanf("%d %s", &inst[i].code, &inst[i].key);
    }

    insertionSortInstruction(inst, 0, (inst_n - 1));

    while (scanf("%d", &nums[nums_count]) != EOF)
    {
        nums_count++;
    }

    for (size_t i = 0; i < nums_count; i++)
    {
        mid = search(nums[i], inst, 0, (inst_n - 1));
        if (mid == -1)
        {
            printf("undefined\n");
        }
        else
        {
            printf("%s\n", inst[mid].key);
        }
    }

    return 0;
}
