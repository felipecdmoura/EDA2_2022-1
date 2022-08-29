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
}

void search(int num, Instruction *inst, int l, int r)
{

    int mid = (r + l) / 2;

    if (num == inst[mid].code)
    {
        printf("%s\n", inst[mid].key);
        return;
    }

    if (l >= r)
    {
        printf("undefined\n");
        return;
    }

    if (num > inst[mid].code)
    {
        search(num, inst, (mid + 1), r);
    }
    else if (num < inst[mid].code)
    {
        search(num, inst, l, (mid - 1));
    }
}

int main(int argc, char const *argv[])
{
    int eof, inst_n, nums;
    int nums_count = 0;

    Instruction inst[50000];

    // nums = (int *)malloc(sizeof(int) * 2);

    scanf("%d", &inst_n);
    // inst = (Instruction *)malloc(sizeof(Instruction) * (inst_n + 1));

    for (size_t i = 0; i < inst_n; i++)
    {
        scanf("%d %[^\n]", &inst[i].code, inst[i].key);
    }

    insertionSortInstruction(inst, 0, (inst_n - 1));

    /* for (size_t i = 0; i < inst_n; i++)
    {
        printf("[%d]\n", inst[i].code);
    } */

    while (eof = scanf("%d", &nums) != EOF)
    {
        search(nums, inst, 0, (inst_n - 1));
        nums_count++;
        // nums = (int *)realloc(nums, (sizeof(int) * (nums_count + 1)));
    }

    /* for (size_t i = 0; i < nums_count; i++)
    {
        printf("{%d}\n", nums[i]);
    } */

    return 0;
}
