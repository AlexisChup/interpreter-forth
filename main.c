#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "constants.h"
#include "displaying.h"
#include "stack_manipulation.h"

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
        display_stack(stack, indexOfTheStack);
        display_return_value(retVal);
        display_is_ok(isOk);
        display_user_action();


        action = getUserAction();
        retVal = 0;

        switch (action)
        {
            case 'u':
                pushValue = getUserNumber('n');
                isOk = push(&pushValue, stack, &indexOfTheStack);

                break;

            case 'o':
                isOk = pop(stack, &indexOfTheStack, &retVal);

                break;

            case 'g':
                isOk = get(stack, &indexOfTheStack, &retVal);

                break;

            case 'U':
                pushValue = getUserNumber('n');
                index = getUserNumber('i');
                isOk = pushN(&pushValue, stack, &indexOfTheStack, index);

                break;

            case 'O':
                index = getUserNumber('i');
                isOk = popN(stack, &indexOfTheStack, &retVal, index);

                break;

            case 'G':
                index = getUserNumber('i');
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