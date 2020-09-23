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

    char action;
    int isContinue = TRUE;
    int isOk = IS_OK;
    int pushValue;
    int retVal = 0;

    while (isContinue == TRUE)
    {
        display(stack, indexOfTheStack);

        printf("\nValeur de retour : %d\n", retVal);
        printf("\nIs ok ? : %d\n", isOk);
        printf("Which actions you want to do ?\n\tq: Quit\n\to: Pop\n\tu: Push\n\tg :Get\n\tt: Top\n");
        scanf("%c", &action);

        while ((getchar()) != '\n'); 

        retVal = 0;

        switch (action)
        {
        case 'q':
            isContinue = FALSE;
            isOk = IS_OK;

            break;
        case 'o':
            isOk = pop(stack, &indexOfTheStack, &retVal);

            break;

        case 'u':
            printf("\nWrite your number / operations: \n");
            scanf("%d", &pushValue);
            while ((getchar()) != '\n'); 
            isOk = push(&pushValue, stack, &indexOfTheStack);

            break;

        case 'g':
            isOk = get(stack, &indexOfTheStack, &retVal);

            break;

        case 't':
            isOk = IS_OK;
            top(stack, &indexOfTheStack, &retVal);

            break;

        default:
            break;
        }
    }
    
    return 0;
}