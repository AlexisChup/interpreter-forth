#include "constants.h"
#include "stack_manipulation.h"
#include "displaying.h"

int stack[MAX_PILE_D];
int indexOfTheStack = 0;

void initStack()
{
    for (int index = 0; index < MAX_PILE_D; index++)
    {
        stack[index] = 0;
    }
}

void removeAllValueFromTheStack()
{
    indexOfTheStack = 0;
}

int Push(long int val)
{
    if(indexOfTheStack < MAX_PILE_D)
    {
        stack[indexOfTheStack] = val;
        indexOfTheStack += 1;

        return 0;
    } else 
    {
        printf("Stack overflow !\n");

        return -1;
    }
}

int Pop(long int *val)
{
    if(indexOfTheStack > 0)
    {
        indexOfTheStack -= 1;
        *val = stack[indexOfTheStack];

        return 0;
    } else 
    {
        *val = NULL_INT;
        printf("The Stack is empty !\n");

        return -1;
    }
}

int Get(long int *val)
{
    if(indexOfTheStack > 0)
    {
        *val = stack[indexOfTheStack -1];

        return 0;
    }
    else
    {
        *val = NULL_INT;
        printf("The Stack is empty !\n");

        return -1;
    }
}

unsigned int Max()
{
    return MAX_PILE_D;
}

unsigned int Top()
{
    return indexOfTheStack;
}

int PushN(long int val, unsigned int index)
{
    if(index <= indexOfTheStack && indexOfTheStack < MAX_PILE_D)
    {
        for (unsigned int i = indexOfTheStack ; i > index - 1; i--)
        {
            stack[i] = stack[i-1];
        }
        
        stack[index] = val;
        indexOfTheStack += 1;

        return 0;
    } else 
    {
        return -1;
    }
}

int PopN(long int *val, unsigned int index)
{
    if(index <= indexOfTheStack && indexOfTheStack > 0)
    {
        *val = stack[index];

        for (unsigned int i = index ; i < indexOfTheStack; i++)
        {
            stack[i] = stack[i+1];
        }

        indexOfTheStack -= 1;

        return 0;
    } else 
    {
        *val = NULL_INT;
        printf("The Stack is empty !\n");
        
        return -1;
    }
}

int GetN(long int *val, unsigned int index)
{
    if(index <= indexOfTheStack && indexOfTheStack > 0)
    {
        *val = stack[index];

        return 0;
    }
    else
    {
        *val = NULL_INT;
        printf("The Stack is empty !\n");
        
        return -1;
    }
}

void DisplayStack()
{
    display_stack(stack, indexOfTheStack);
}