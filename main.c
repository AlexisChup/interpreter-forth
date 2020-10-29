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
    long int retVal = NULL_VAR;

    unsigned int index;
    clearConsole();

    while (isContinue == TRUE)
    {
        DisplayStack();
        display_return_value(retVal);
        display_is_ok(isOk);
        display_user_action();


        action = getUserAction();
        retVal = 0;
        clearConsole();
        DisplayStack();

        switch (action)
        {
            case 'u':
                printf("Push method\n");
                pushValue = getUserNumber('n');
                isOk = Push(pushValue);

                break;

            case 'o':
                printf("Pop method\n");
                isOk = Pop(&retVal);

                break;

            case 'g':
                printf("Get method\n");
                isOk = Get(&retVal);

                break;

            case 'U':
                printf("Push with an index method\n");
                pushValue = getUserNumber('n');
                index = getUserNumber('i');
                isOk = PushN(pushValue, index);

                break;

            case 'O':
                printf("Pop with an index method\n");
                index = getUserNumber('i');
                isOk = PopN(&retVal, index);

                break;

            case 'G':
                printf("Get with an index method\n");
                index = getUserNumber('i');
                isOk = GetN(&retVal, index);

                break;
            
            case 't':
                printf("Top method\n");
                isOk = IS_OK;
                retVal = Top();

                break;
            
            case 'm':
                printf("Max method\n");
                isOk = IS_OK;
                retVal = Max();

                break;

            case 'q':
                printf("Quit\n");
                isContinue = FALSE;
                isOk = IS_OK;

                break;

            default:
                display_error_message();
                printf("You need to type letter in the list\n");

                isOk = IS_NOT_OK;
                retVal = NULL_VAR;

                break;
        }
    }
    
    return 0;
}