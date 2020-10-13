#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include "constants.h"

#include "testsMethods.h"

int main(void)
{
    system("clear");

    int stack[MAX_PILE_D];
    int indexOfTheStack;

    initStack(stack);

    int isOk;
    int pushValue;
    int retVal;
    unsigned int action;
    unsigned int index;

    unsigned int numberOfMethodsToTest = 8;

    for (unsigned int action = 0; action < numberOfMethodsToTest; action++)
    {
        isOk = IS_OK;
        retVal = 0;
        indexOfTheStack = 0;

        switch (action)
        {
        case 0:
            testPushMethod(stack, &indexOfTheStack, &isOk);

            break;
        case 1:
            testPopMethod(stack, &indexOfTheStack, &isOk);

            break;

        case 2:
            testGetMethod(stack, &indexOfTheStack, &isOk);

            break;

        case 3:
            testPushNMethod(stack, &indexOfTheStack, &isOk);

            break;

        case 4:
            testPopNMethod(stack, &indexOfTheStack, &isOk);

            break;

        case 5:
            testGetNMethod(stack, &indexOfTheStack, &isOk);

            break;

        case 6:
            testTopMethod(stack, &indexOfTheStack, &isOk);

            break;

        case 7:
            testMaxMethod(&isOk);

            break;

        default:
            break;
        }
    }
}
    