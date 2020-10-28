#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include "constants.h"

#include "units_tests_methods.h"

int main(void)
{
    unsigned int numberOfMethodsToTest = 8;

    initStack();

    printf("-------------------------------------\n\n");
    printf("-- FIRST AND SECOND PART UNIT TEST --\n\n");
    printf("\t✓\tMEANS THAT METHOD RETURN 0 FOR OK\n");
    printf("\t❌\tMEANS THAT METHOD RETURN -1 FOR AN ERROR\n");
    printf("\n-------------------------------------\n\n");
    for (unsigned int action = 0; action < numberOfMethodsToTest; action++)
    {
        switch (action)
        {
        case 0:
            testPushMethod();

            break;
        case 1:
            testPopMethod();

            break;

        case 2:
            testGetMethod();

            break;

        case 3:
            testPushNMethod();

            break;

        case 4:
            testPopNMethod();

            break;

        case 5:
            testGetNMethod();

            break;

        case 6:
            testTopMethod();

            break;

        case 7:
            testMaxMethod();

            break;

        default:
            break;
        }
    }

    printf("\t\t✓✓  ALL TESTS PASSED  ✓✓\n\n");
}
    