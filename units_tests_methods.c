#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "constants.h"
#include "stack_manipulation.h"

#include "units_tests_methods.h"

#include "displaying.h"

void printResultOfTest(int *isOk)
{
    if(*isOk == IS_OK)
    {
        printf("\t\t✓\n\n");
    } else
    {
        printf("\t\t❌\n\n");
    }
}

void printReturnedValue(int retVal)
{
    if(retVal == NULL_INT)
    {
        printf("\tx None value was returned\n");
    } else
    {
        printf("\tx Value returned: %d\n", retVal);
    }
    
}

int insertNRandomNumberInStack(int stack[MAX_PILE_D], unsigned int numberOfRandomNumber, int *indexOfTheStack, int *isOk)
{
    int pushValue;
    int returnValueFromPush;
    int newIsOk = 1;
    srand(time(NULL));   // Initialization, should only be called once.

    for (unsigned index = 0; index < numberOfRandomNumber; index++)
    {
        pushValue = rand() / 100000;      // Returns a pseudo-random integer between 0 and RAND_MAX.
        returnValueFromPush = push(&pushValue, stack, indexOfTheStack);

        newIsOk &= (returnValueFromPush == IS_OK) ? 1 : 0;
    }

    if(newIsOk)
    {
        *isOk = IS_OK;
    } else {
        *isOk = IS_NOT_OK;
    }
}

void testPushMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk)
{
    printf("-- TEST PUSH METHOD --\n\n");

    removeAllValueFromTheStack(indexOfTheStack);
    *isOk = IS_OK;

    printf("\tTest inserting 5 numbers in stack:\n");
    insertNRandomNumberInStack(stack, 5, indexOfTheStack, isOk);
    printResultOfTest(isOk);

    removeAllValueFromTheStack(indexOfTheStack);
    *isOk = IS_OK;

    printf("\tTest inserting 101 numbers in stack when max amount of elements is 100:\n");
    insertNRandomNumberInStack(stack, 101, indexOfTheStack, isOk);
    printResultOfTest(isOk);
}

void testPopMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk)
{
    int retVal;

    printf("-- TEST POP METHOD --\n\n");

    removeAllValueFromTheStack(indexOfTheStack);
    insertNRandomNumberInStack(stack, 5, indexOfTheStack, isOk);
    *isOk = IS_OK;

    printf("\tTest popping 1 number when stack is NOT EMPTY:\n");
    *isOk = pop(stack, indexOfTheStack, &retVal);
    printReturnedValue(retVal);
    printResultOfTest(isOk);

    removeAllValueFromTheStack(indexOfTheStack);
    *isOk = IS_OK;

    printf("\tTest popping 1 number when stack is EMPTY:\n");
    *isOk = pop(stack, indexOfTheStack, &retVal);
    printReturnedValue(retVal);
    printResultOfTest(isOk);
}

void testGetMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk)
{
    int retVal;

    printf("-- TEST GET METHOD --\n\n");

    removeAllValueFromTheStack(indexOfTheStack);
    insertNRandomNumberInStack(stack, 5, indexOfTheStack, isOk);
    *isOk = IS_OK;

    printf("\tTest getting the last number when stack is NOT EMPTY:\n");
    *isOk = get(stack, indexOfTheStack, &retVal);
    printReturnedValue(retVal);
    printResultOfTest(isOk);

    removeAllValueFromTheStack(indexOfTheStack);
    *isOk = IS_OK;

    printf("\tTest getting the last number when stack is EMPTY:\n");
    *isOk = get(stack, indexOfTheStack, &retVal);
    printReturnedValue(retVal);
    printResultOfTest(isOk);
}

void testTopMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk)
{
    printf("-- TEST TOP METHOD --\n\n");

    int retVal;
    int numberOfElements = 10;

    removeAllValueFromTheStack(indexOfTheStack);
    insertNRandomNumberInStack(stack, numberOfElements, indexOfTheStack, isOk);
    *isOk = IS_OK;

    printf("\tTest counting numbers when there are %d in stack:\n", numberOfElements);
    top(indexOfTheStack, &retVal);
    printReturnedValue(retVal);
    printResultOfTest(isOk);

    removeAllValueFromTheStack(indexOfTheStack);
    *isOk = IS_OK;

    printf("\tTest counting numbers when the stack is EMPTY:\n");
    top(indexOfTheStack, &retVal);
    printReturnedValue(retVal);
    printResultOfTest(isOk);  
}

void testMaxMethod(int *isOk)
{
    int retVal;

    printf("-- TEST MAX METHOD --\n\n");

    printf("Test getting the maximum amount of elements:\n");
    max(&retVal);
    *isOk = IS_OK;
    printReturnedValue(retVal);
    printResultOfTest(isOk);
}

void testPushNMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk)
{
    printf("-- TEST PUSH WITH INDEX METHOD --\n\n");

    int pushValue = 747;

    removeAllValueFromTheStack(indexOfTheStack);
    insertNRandomNumberInStack(stack, 10, indexOfTheStack, isOk);
    *isOk = IS_OK;

    printf("\tTest inserting at index = 3, when there are numbers in stack:\n");
    *isOk = pushN(&pushValue, stack, indexOfTheStack, 3);
    printResultOfTest(isOk);

    removeAllValueFromTheStack(indexOfTheStack);
    *isOk = IS_OK;

    printf("\tTest inserting at index = 3, when stack is EMPTY:\n");
    *isOk = pushN(&pushValue, stack, indexOfTheStack, 3);
    printResultOfTest(isOk);
}

void testPopNMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk)
{
    int retVal;
    int index = 3;

    printf("-- TEST POP WITH INDEX METHOD --\n\n");

    removeAllValueFromTheStack(indexOfTheStack);
    insertNRandomNumberInStack(stack, 5, indexOfTheStack, isOk);
    *isOk = IS_OK;

    printf("\tTest popping 1 number at index = 3, when stack is NOT EMPTY:\n");
    *isOk = popN(stack, indexOfTheStack, &retVal, index);
    printReturnedValue(retVal);
    printResultOfTest(isOk);

    removeAllValueFromTheStack(indexOfTheStack);
    *isOk = IS_OK;

    printf("\tTest popping 1 number at index = 3, when stack is EMPTY:\n");
    *isOk = popN(stack, indexOfTheStack, &retVal, index);
    printReturnedValue(retVal);
    printResultOfTest(isOk);
}

void testGetNMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk)
{
    int retVal;
    int index = 7;

    printf("-- TEST GET WITH INDEX METHOD --\n\n");

    removeAllValueFromTheStack(indexOfTheStack);
    insertNRandomNumberInStack(stack, 10, indexOfTheStack, isOk);
    *isOk = IS_OK;

    printf("\tTest getting number at index = %d when stack is NOT EMPTY:\n", index);
    *isOk = getN(stack, indexOfTheStack, &retVal, index);
    printReturnedValue(retVal);
    printResultOfTest(isOk);

    removeAllValueFromTheStack(indexOfTheStack);
    *isOk = IS_OK;

    printf("\tTest getting number at index = %d when stack is EMPTY:\n", index);
    *isOk = getN(stack, indexOfTheStack, &retVal, index);
    printReturnedValue(retVal);
    printResultOfTest(isOk);
}