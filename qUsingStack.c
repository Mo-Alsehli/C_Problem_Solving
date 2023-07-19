/*
-- Description:
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *stack1;
    int *stack2;
    int top;
    int tail;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->stack1 = (int *)malloc(sizeof(int) * 1000);
    q->stack2 = (int *)malloc(sizeof(int) * 1000);
    q->top = -1;
    q->tail = 0;

    return q;
}

void myQueuePush(MyQueue *obj, int x)
{
    obj->top++;
    obj->stack1[obj->top] = x;
}

int myQueuePop(MyQueue *obj)
{
    int size = obj->top, i;
    for (i = obj->tail + 1; i < size; i++)
    {
        obj->stack2[i] = obj->stack1[i];
    };
    int popped = obj->stack1[obj->tail];
    obj->tail++;
    for (i = obj->tail + 1; i < size; i++)
    {
        obj->stack1[i] = obj->stack2[i];
    };

    return popped;
}

int myQueuePeek(MyQueue *obj)
{
    return obj->stack1[obj->tail];
}

bool myQueueEmpty(MyQueue *obj)
{
    return obj->top == -1 || !(obj->tail <= obj->top);
}

void myQueueFree(MyQueue *obj)
{
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

int main()
{

    MyQueue *obj = myQueueCreate();
    myQueuePush(obj, 10);
    myQueuePush(obj, 20);
    myQueuePush(obj, 30);

    int param_2 = myQueuePop(obj);
    printf("Popped = %d\n", param_2);
    int param_3 = myQueuePeek(obj);
    printf("Top = %d\n", param_3);
    int param_4 = (int)myQueueEmpty(obj);
    printf("Is Empty = %d\n", param_4);
    myQueueFree(obj);

    return 0;
}