#include <stdio.h>
#include <stdlib.h> 

#include "constants.h"
#include "displaying.h"
#include "stackManipulation.h"

#include "utils.h"



int main(void)
{
    int stack[MAX_PILE_D];
    int indexOfTheStack = 0;

    initStack(stack);

    char action;
    int isContinue = TRUE;
    int isOk = IS_OK;
    int pushValue;
    int retVal = 0;
    unsigned int index;

    while (isContinue == TRUE)
    {
        display(stack, indexOfTheStack);

        printf("\nValeur de retour : %d\n", retVal);
        printf("\nIs ok ? : %d\n", isOk);
        printf("Which actions you want to do ?\n\tu: Push\t\t\t\to: Pop\t\t\t\tg :Get\n\tU: Push with selected index\tO: Pop with selected index\tG: Get with selected index\n\tt: Top\t\t\t\tm: Max\n\tq: Quit\n");
        scanf("%c", &action);

        emptyBuffer();

        retVal = 0;

        switch (action)
        {
        case 'u':
            printf("\nWrite your number / operations: \n");
            scanf("%d", &pushValue);
            emptyBuffer();

            isOk = push(&pushValue, stack, &indexOfTheStack);

            break;

        case 'o':
            isOk = pop(stack, &indexOfTheStack, &retVal);

            break;

        case 'g':
            isOk = get(stack, &indexOfTheStack, &retVal);

            break;

        case 'U':
            printf("\nWrite your number / operations: \n");
            scanf("%d", &pushValue);
            emptyBuffer();

            printf("\nWrite the index where write the number: \n");
            scanf("%d", &index);
            emptyBuffer();

            isOk = pushN(&pushValue, stack, &indexOfTheStack, index);
            break;

        case 'O':
            printf("\nWrite the index where remove the number: \n");
            scanf("%d", &index);
            emptyBuffer();

            isOk = popN(stack, &indexOfTheStack, &retVal, index);

            break;

        case 'G':
            printf("\nWrite the index where get the number: \n");
            scanf("%d", &index);
            emptyBuffer();

            isOk = getN(stack, &indexOfTheStack, &retVal, index);

            break;
        
        case 't':
            isOk = IS_OK;
            top(&indexOfTheStack, &retVal);

            break;
        
        case 'm':
            isOk = IS_OK;
            max(&retVal);

            break;

        case 'q':
            isContinue = FALSE;
            isOk = IS_OK;

            break;

        default:
            break;
        }
    }
    
    return 0;
}