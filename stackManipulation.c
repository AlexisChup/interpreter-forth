#include "constants.h"

void initStack(int stack[])
{
    for (int index = 0; index < MAX_PILE_D; index++)
    {
        stack[index] = 0;
    }
}

void removeAllValueFromTheStack(int *indexOfTheStack)
{
    *indexOfTheStack = 0;
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
        *retVal = NULL_INT;
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
        *retVal = NULL_INT;
        printf("The Stack is empty !\n");

        return -1;
    }
}

unsigned int top(int *indexOfTheStack, int *retVal)
{
    *retVal = *indexOfTheStack;
}

int pushN(int *value, int stack[MAX_PILE_D], int *indexOfTheStack, unsigned int index)
{
    if(index <= *indexOfTheStack && *indexOfTheStack < MAX_PILE_D)
    {
        for (unsigned int i = *indexOfTheStack ; i > index - 1; i--)
        {
            stack[i] = stack[i-1];
        }
        
        stack[index] = *value;
        *indexOfTheStack += 1;

        return 0;
    } else 
    {
        return -1;
    }
}

int popN(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal, unsigned int index)
{
    if(index <= *indexOfTheStack && *indexOfTheStack > 0)
    {
        *retVal = stack[index];

        for (unsigned int i = index ; i < *indexOfTheStack; i++)
        {
            stack[i] = stack[i+1];
        }

        *indexOfTheStack -= 1;

        return 0;
    } else 
    {
        *retVal = NULL_INT;
        printf("The Stack is empty !\n");
        
        return -1;
    }
}

int getN(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal, unsigned int index)
{
    if(index <= *indexOfTheStack && *indexOfTheStack > 0)
    {
        *retVal = stack[index];

        return 0;
    }
    else
    {
        *retVal = NULL_INT;
        printf("The Stack is empty !\n");
        
        return -1;
    }
}