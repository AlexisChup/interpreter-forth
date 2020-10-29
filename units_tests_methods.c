#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "constants.h"
#include "stack_manipulation.h"

#include "units_tests_methods.h"

#include "displaying.h"


void printResultOfTest()
{
    if(isOk == IS_OK)
    {
        printf("\t\t✓\n\n");
    } else
    {
        printf("\t\t❌\n\n");
    }
}

void printReturnedValue(long int retVal)
{
    if(retVal == NULL_VAR)
    {
        printf("\t* None value was returned\n");
    } else
    {
        printf("\t* Value returned: %ld\n", retVal);
    }   
}

int insertNRandomNumberInStack(unsigned int numberOfRandomNumber)
{
    long int pushValue;
    int returnValueFromPush;
    int isOnlyIsOk = TRUE;
    srand(time(NULL));   // Initialization, should only be called once.

    for (unsigned index = 0; index < numberOfRandomNumber; index++)
    {
        pushValue = rand() / 100000;      // Returns a pseudo-random integer between 0 and RAND_MAX.
        returnValueFromPush = Push(pushValue);

        isOnlyIsOk &= (returnValueFromPush == IS_OK) ? TRUE : FALSE;
    }

    isOk = (isOnlyIsOk) ? IS_OK : IS_NOT_OK;
}

void updateNumberOfErrorAndIsOkAccordingToExpectedValue(int expectedValue)
{
    isOk = (isOk == expectedValue) ? IS_OK : IS_NOT_OK;

    if(isOk == IS_NOT_OK)
    {
        numberOfErrors++;
    }
}

void testPushMethod()
{
    printf("-- TEST PUSH METHOD --\n\n");

    removeAllValueFromTheStack();
    isOk = IS_OK;

    printf("\tTest inserting 5 numbers in stack:\n");
    insertNRandomNumberInStack(5);

    //isOk should be IS_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_OK); 

    printResultOfTest();

    removeAllValueFromTheStack();
    isOk = IS_OK;

    printf("\tTest inserting 101 numbers in stack when Max amount of elements is 100:\n");
    insertNRandomNumberInStack(101);

    //isOk should be IS_NOT_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_NOT_OK); 

    printResultOfTest();
}

void testPopMethod()
{
    long int retVal;

    printf("-- TEST POP METHOD --\n\n");

    removeAllValueFromTheStack();
    insertNRandomNumberInStack(5);
    isOk = IS_OK;

    printf("\tTest popping 1 number when stack is NOT EMPTY:\n");
    isOk = Pop(&retVal);

    //isOk should be IS_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_OK); 

    printReturnedValue(retVal);
    printResultOfTest();

    removeAllValueFromTheStack();
    isOk = IS_OK;

    printf("\tTest popping 1 number when stack is EMPTY:\n");
    isOk = Pop(&retVal);

    // isOk should be IS_NOT_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_NOT_OK);

    printReturnedValue(retVal);
    printResultOfTest();
}

void testGetMethod()
{
    long int retVal;

    printf("-- TEST GET METHOD --\n\n");

    removeAllValueFromTheStack();
    insertNRandomNumberInStack(5);
    isOk = IS_OK;

    printf("\tTest getting the last number when stack is NOT EMPTY:\n");
    isOk = Get(&retVal);

    //isOk should be IS_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_OK); 

    printReturnedValue(retVal);
    printResultOfTest();

    removeAllValueFromTheStack();
    isOk = IS_OK;

    printf("\tTest getting the last number when stack is EMPTY:\n");
    isOk = Get(&retVal);

    //isOk should be IS_NOT_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_NOT_OK); 

    printReturnedValue(retVal);
    printResultOfTest();
}

void testTopMethod()
{
    printf("-- TEST TOP METHOD --\n\n");

    long int retVal;
    int numberOfElements = 10;

    removeAllValueFromTheStack();
    insertNRandomNumberInStack(numberOfElements);
    isOk = IS_OK;

    printf("\tTest counting numbers when there are %d in stack:\n", numberOfElements);
    retVal = Top();
    printReturnedValue(retVal);
    printResultOfTest();

    removeAllValueFromTheStack();
    isOk = IS_OK;

    printf("\tTest counting numbers when the stack is EMPTY:\n");
    retVal = Top();
    printReturnedValue(retVal);
    printResultOfTest();  
}

void testMaxMethod()
{
    long int retVal;

    printf("-- TEST MAX METHOD --\n\n");

    printf("Test getting the maximum amount of elements:\n");
    retVal = Max();
    isOk = IS_OK;
    printReturnedValue(retVal);
    printResultOfTest();
}

void testPushNMethod()
{
    printf("-- TEST PUSH WITH INDEX METHOD --\n\n");

    long int pushValue = 747;

    removeAllValueFromTheStack();
    insertNRandomNumberInStack(10);
    isOk = IS_OK;

    printf("\tTest inserting at index = 3, when there are numbers in stack:\n");
    isOk = PushN(pushValue, 3);

    //isOk should be IS_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_OK); 

    printResultOfTest();

    removeAllValueFromTheStack();
    isOk = IS_OK;

    printf("\tTest inserting at index = 3, when stack is EMPTY:\n");
    isOk = PushN(pushValue, 3);

    //isOk should be IS_NOT_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_NOT_OK); 

    printResultOfTest();
}

void testPopNMethod()
{
    long int retVal;
    int index = 3;

    printf("-- TEST POP WITH INDEX METHOD --\n\n");

    removeAllValueFromTheStack();
    insertNRandomNumberInStack(5);
    isOk = IS_OK;

    printf("\tTest popping 1 number at index = 3, when stack is NOT EMPTY:\n");
    isOk = PopN(&retVal, index);

    //isOk should be IS_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_OK);

    printReturnedValue(retVal);
    printResultOfTest();

    removeAllValueFromTheStack();
    isOk = IS_OK;

    printf("\tTest popping 1 number at index = 3, when stack is EMPTY:\n");
    isOk = PopN(&retVal, index);

    //isOk should be IS_NOT_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_NOT_OK); 

    printReturnedValue(retVal);
    printResultOfTest();
}

void testGetNMethod()
{
    long int retVal;
    int index = 7;

    printf("-- TEST GET WITH INDEX METHOD --\n\n");

    removeAllValueFromTheStack();
    insertNRandomNumberInStack(10);
    isOk = IS_OK;

    printf("\tTest getting number at index = %d when stack is NOT EMPTY:\n", index);
    isOk = GetN(&retVal, index);

    //isOk should be IS_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_OK); 

    printReturnedValue(retVal);
    printResultOfTest();

    removeAllValueFromTheStack();
    isOk = IS_OK;

    printf("\tTest getting number at index = %d when stack is EMPTY:\n", index);
    isOk = GetN(&retVal, index);

    //isOk should be IS_NOT_OK
    updateNumberOfErrorAndIsOkAccordingToExpectedValue(IS_NOT_OK); 

    printReturnedValue(retVal);
    printResultOfTest();
}