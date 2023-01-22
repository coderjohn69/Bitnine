#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag
{
    ADD,
    SUB,
    MUL,
    DIV,
    FIB
} TypeTag;

typedef struct Node
{
    TypeTag type;
    int value;
} Node;

Node *makeFunc(TypeTag type, int a, int b)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->type = type;
    if (type == ADD)
    {
        newNode->value = a + b;
    }
    else if (type == SUB)
    {
        newNode->value = a - b;
    }
    else if (type == MUL)
    {
        newNode->value = a * b;
    }
    else if (type == DIV)
    {
        if (b == 0)
        {
            printf("\n Division by zero not allowed");
            exit(0);
        }
        newNode->value = a / b;
    }
    else if (type == FIB)
    {
        int n = a, prev = 0, cur = 1, next;
        for (int i = 1; i <= n; i++)
        {
            next = prev + cur;
            prev = cur;
            cur = next;
        }
        newNode->value = prev;
    }
    return newNode;
}

void calc(Node *node)
{
    if (node->type == ADD)
    {
        printf("add : %d\n", node->value);
    }
    else if (node->type == SUB)
    {
        printf("sub : %d\n", node->value);
    }
    else if (node->type == MUL)
    {
        printf("mul : %d\n", node->value);
    }
    else if (node->type == DIV)
    {
        printf("div : %d\n", node->value);
    }
    else if (node->type == FIB)
    {
        printf("fibo : %d\n", node->value);
    }
}

int main()
{
    Node *add = makeFunc(ADD, 10, 6);
    Node *mul = makeFunc(MUL, 5, 4);
    Node *sub = makeFunc(SUB, mul->value, add->value);
    Node *fibo = makeFunc(FIB, sub->value, 0);
    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);
    return 0;
}
