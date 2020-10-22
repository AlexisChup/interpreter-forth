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
int insertNRandomNumberInStack(unsigned int numberOfRandomNumber, int *isOk);

void testPushMethod(int *isOk);
void testPopMethod(int *isOk);
void testGetMethod(int *isOk);

void testTopMethod(int *isOk);
void testMaxMethod(int *isOk);

void testPushNMethod(int *isOk);
void testPopNMethod(int *isOk);
void testGetNMethod(int *isOk);

#endif