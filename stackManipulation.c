#include "constants.h"

void initStack(int stack[])
{
    for (int index = 0; index < MAX_PILE_D; index++)
    {
        stack[index] = 0;
    }
}

int push(int *value, int stack[MAX_PILE_D], int *indexOfTheStack)
{
    if(*indexOfTheStack < MAX_PILE_D)
    {
        stack[*indexOfTheStack] = *value;
        *indexOfTheStack += 1;

        return 0;
    } else 
    {
        printf("Stack overflow !\n");

        return -1;
    }
}

int pop(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal)
{
    if(*indexOfTheStack > 0)
    {
        *indexOfTheStack -= 1;
        *retVal = stack[*indexOfTheStack];

        return 0;
    } else 
    {
        printf("The Stack is empty !\n");

        return -1;
    }
}

int get(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal)
{
    if(*indexOfTheStack > 0)
    {
        *retVal = stack[*indexOfTheStack -1];

        return 0;
    }
    else
    {
        return -1;
    }
}

unsigned int top(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal)
{
    if(*indexOfTheStack > 0)
    {
        *retVal = stack[*indexOfTheStack-1];
    } else 
    {
        *retVal = 0;
    }
}