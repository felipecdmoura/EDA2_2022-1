#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack
{
    struct stack *prev;
    char str[100];
} stack;

struct stack *prevNode(struct stack *pt)
{
    if (pt->prev == NULL)
    {
        return pt;
    }
    else
    {
        pt = pt->prev;
    }

    return pt;
}
struct stack *nextNode(struct stack *pt)
{
    stack *new = (stack *)malloc(sizeof(stack));
    stack *temp = pt;

    pt = new;
    pt->prev = temp;

    return pt;
}

int main(int argc, char const *argv[])
{

    stack *head = (stack *)malloc(sizeof(stack));
    int eof = 0;
    char ins_str[108] = "", temp[100] = "NULL";

    head->prev = NULL;
    strcpy(head->str, "NULL");

    while (eof != EOF)
    {
        eof = scanf("%[^\n]%*c", ins_str);

        if (eof == EOF)
        {
            break;
        }
        else if (strcmp(ins_str, "desfazer") == 0)
        {

            if (head->prev == NULL)
            {
                printf("NULL\n");
            }
            else
            {
                printf("%s\n", head->str);
            }

            head = prevNode(head);
        }
        else
        {
            for (size_t i = 8; i <= 107; i++)
            {
                strcpy(&temp[(i - 8)], &ins_str[i]);
            }

            head = nextNode(head);
            strcpy(head->str, temp);
        }
    }

    return 0;
}
