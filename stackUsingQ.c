#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *queue1;
    int *queue2;
    int topElement;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->queue1 = (int *)malloc(sizeof(int) * 1000);
    stack->queue2 = (int *)malloc(sizeof(int) * 1000);
    stack->topElement = -1;
    return stack;
}

void myStackPush(MyStack *obj, int x)
{
    obj->topElement++;
    obj->queue1[obj->topElement] = x;
}

int myStackPop(MyStack *obj)
{
    int size = obj->topElement + 1;

    for (int i = 0; i < size - 1; i++)
    {
        obj->queue2[i] = obj->queue1[i];
    }

    int poppedElement = obj->queue1[size - 1];
    obj->topElement--;

    for (int i = 0; i < size - 1; i++)
    {
        obj->queue1[i] = obj->queue2[i];
    }

    return poppedElement;
}

int myStackTop(MyStack *obj)
{
    return obj->queue1[obj->topElement];
}

bool myStackEmpty(MyStack *obj)
{
    return obj->topElement == -1;
}

void myStackFree(MyStack *obj)
{
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}

int main()
{
    MyStack *stack = myStackCreate();

    myStackPush(stack, 1);
    myStackPush(stack, 2);
    myStackPush(stack, 3);
    myStackPush(stack, 4);
    myStackPush(stack, 2);

    printf("Top: %d\n", myStackTop(stack));

    printf("Popped: %d\n", myStackPop(stack));

    printf("Top: %d\n", myStackTop(stack));

    myStackFree(stack);

    return 0;
}
