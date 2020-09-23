#include <stdio.h>
#include <stdlib.h> 

#include "constants.h"
#include "displaying.h"
#include "stackManipulation.h"



int main(void)
{
    int stack[MAX_PILE_D];
    int indexOfTheStack = 0;

    initStack(stack);

    int isOk = IS_OK;
    int pushValue;
    int retVal = 0;
    unsigned int action;
    unsigned int index;


    printf("\nValeur de retour : %d\n", retVal);
    printf("\nIs ok ? : %d\n", isOk);

    retVal = 0;

    unsigned int numberOfMethodsToTest = 7;

    for (unsigned int action = 0; action < numberOfMethodsToTest; action++)
    {
        switch (action)
        {
        case 0:
            printf("\nWrite your number / operations: \n");
            scanf("%d", &pushValue);
            while ((getchar()) != '\n'); 
            isOk = push(&pushValue, stack, &indexOfTheStack);

            break;
        case 1:
            isOk = pop(stack, &indexOfTheStack, &retVal);

            break;

        case 2:
            isOk = get(stack, &indexOfTheStack, &retVal);

            break;

        case 3:
            printf("\nWrite your number / operations: \n");
            scanf("%d", &pushValue);
            while ((getchar()) != '\n');

            printf("\nWrite the index where write the number: \n");
            scanf("%d", &index);
            while ((getchar()) != '\n');

            isOk = pushN(&pushValue, stack, &indexOfTheStack, index);

            break;

        case 4:
            printf("\nWrite the index where remove the number: \n");
            scanf("%d", &index);
            while ((getchar()) != '\n');

            isOk = popN(stack, &indexOfTheStack, &retVal, index);

            break;

        case 5:
            printf("\nWrite the index where get the number: \n");
            scanf("%d", &index);
            while ((getchar()) != '\n');

            isOk = getN(stack, &indexOfTheStack, &retVal, index);

            break;

        case 6:
            isOk = IS_OK;
            top(stack, &indexOfTheStack, &retVal);

            break;

        case 7:
            isOk = IS_OK;

            break;

        default:
            break;
        }
    }
}
    