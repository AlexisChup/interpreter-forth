#ifndef TESTS_METHODS_H
#define TESTS_METHODS_H
#include "constants.h"


/*
    *used to make more beautiful print in terminal
*/
void printResultOfTest(int *isOk);
void printReturnedValue(int retVal);

/*
    *used to insert X random number in the stack for tests
*/
int insertNRandomNumberInStack(long int stack[MAX_PILE_D], unsigned int numberOfRandomNumber, int *indexOfTheStack, int *isOk);

void testPushMethod(long int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testPopMethod(long int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testGetMethod(long int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);

void testTopMethod(long int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testMaxMethod(int *isOk);

void testPushNMethod(long int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testPopNMethod(long int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testGetNMethod(long int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);

#endif