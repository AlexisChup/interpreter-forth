#include "constants.h"
#include "stack_manipulation.h"
#include "displaying.h"

void initStack()
{
    indexOfTheStack = 0;

    for (int index = 0; index < MAX_PILE_D; index++)
    {
        stack[index] = NULL_VAR;
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

        return IS_OK;
    } else 
    {
        printf("Stack overflow !\n");

        return IS_NOT_OK;
    }
}

int Pop(long int *val)
{
    if(indexOfTheStack > 0)
    {
        Get(val);
        indexOfTheStack -= 1;

        return IS_OK;
    } else 
    {
        *val = NULL_VAR;
        printf("The Stack is empty !\n");

        return IS_NOT_OK;
    }
}

int Get(long int *val)
{
    if(indexOfTheStack > 0)
    {
        *val = stack[indexOfTheStack -1];

        return IS_OK;
    }
    else
    {
        *val = NULL_VAR;
        printf("The Stack is empty !\n");

        return IS_NOT_OK;
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

        return IS_OK;
    } else 
    {
        printf("You must insert a number with an index :\n\t0 =< index =< %d\n", indexOfTheStack);
        printf("That's why %d isn't correct\n", index);

        return IS_NOT_OK;
    }
}

int PopN(long int *val, unsigned int index)
{
    printf("PopN index: %d, indexOfTheStack : %d, there is a problem here", index, indexOfTheStack);
    if(index <= indexOfTheStack-1 && indexOfTheStack > 0)
    {
        *val = stack[index];

        for (unsigned int i = index ; i < indexOfTheStack; i++)
        {
            stack[i] = stack[i+1];
        }

        indexOfTheStack -= 1;

        return IS_OK;
    } else 
    {
        *val = NULL_VAR;
        printf("There is no value in stack for index : %d\n", index);
        
        return IS_NOT_OK;
    }
}

int GetN(long int *val, unsigned int index)
{
    if(index <= indexOfTheStack && indexOfTheStack > 0)
    {
        *val = stack[index];

        return IS_OK;
    }
    else
    {
        *val = NULL_VAR;
        printf("There is no value in stack for index : %d\n", index);
        
        return IS_NOT_OK;
    }
}

void DisplayStack()
{
    display_stack(indexOfTheStack);
}