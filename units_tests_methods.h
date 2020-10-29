#ifndef TESTS_METHODS_H
#define TESTS_METHODS_H
#include "constants.h"

int isOk;
unsigned int numberOfErrors;

/*
    *used to make more beautiful print in terminal
*/
void printResultOfTest();
void printReturnedValue(long int retVal);

/*
    *used to insert X random number in the stack for tests
*/
int insertNRandomNumberInStack(unsigned int numberOfRandomNumber);

void updateNumberOfErrorAndIsOkAccordingToExpectedValue(int expectedValue);

void testPushMethod();
void testPopMethod();
void testGetMethod();

void testTopMethod();
void testMaxMethod();

void testPushNMethod();
void testPopNMethod();
void testGetNMethod();

#endif