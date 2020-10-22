#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "constants.h"
#include "displaying.h"
#include "stack_manipulation.h"

#include "utils.h"



int main(void)
{
    initStack();

    char action;

    int isContinue = TRUE;
    int isOk = IS_OK;

    long int pushValue;
    long int retVal = 0;

    unsigned int index;

    while (isContinue == TRUE)
    {
        DisplayStack();
        display_return_value(retVal);
        display_is_ok(isOk);
        display_user_action();


        action = getUserAction();
        retVal = 0;

        switch (action)
        {
            case 'u':
                pushValue = getUserNumber('n');
                isOk = Push(pushValue);

                break;

            case 'o':
                isOk = Pop(&retVal);

                break;

            case 'g':
                isOk = Get(&retVal);

                break;

            case 'U':
                pushValue = getUserNumber('n');
                index = getUserNumber('i');
                isOk = PushN(pushValue, index);

                break;

            case 'O':
                index = getUserNumber('i');
                isOk = PopN(&retVal, index);

                break;

            case 'G':
                index = getUserNumber('i');
                isOk = GetN(&retVal, index);

                break;
            
            case 't':
                isOk = IS_OK;
                retVal = Top();

                break;
            
            case 'm':
                isOk = IS_OK;
                retVal = Max();

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